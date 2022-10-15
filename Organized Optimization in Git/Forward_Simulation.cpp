#include "Prepared_Objects.h"
#include<vector>
#include "Data.h"
#include "JSON.h"
#include<list>
#include<algorithm>
std::multimap<std::string, std::shared_ptr<All_Buildings_Units>> Prepared_Objects::builder_map = { {"nexus",std::make_shared<Builder>("nexus")  } };
std::multimap<std::string, std::shared_ptr<All_Buildings_Units>> Prepared_Objects::building_map;
std::multimap<std::string, std::shared_ptr<All_Buildings_Units>> Prepared_Objects::unit_map = { {"probe",std::make_shared<Units>("probe")},{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") } };

void Prepared_Objects::Reset_Containers()
{
	All_Buildings_Units::count = 0;
	builder_map.clear();
	builder_map = { {"nexus",std::make_shared<Builder>("nexus")  } };
	building_map.clear();
	unit_map.clear();
	unit_map = { {"probe",std::make_shared<Units>("probe")},{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") },{"probe",std::make_shared<Units>("probe") } };

	//std::cout << "Reset of containers done!" << std::endl;
}

int forward_simulation(std::vector<std::pair<char, std::string> >& modified_list,bool print =true)
{
	int t = 1;
	int i = 0;
	bool is_i_same = false;
	int mineral_distribution = Resources::workers;
	int gas_distribution = 0;
	int nexus_count = 1;
	std::size_t ready_units = 0;
	int remaining_units = modified_list.size();
	int delay = 0;
	Data info;
	bool chrono_boost = false;
	int delay_in_chrono = 0;
	int event_count = 0;
	int total_supply = 10;
	int assimilator_count = 0;
	int action_count = 0;
	std::shared_ptr<All_Buildings_Units> chrono_target = nullptr;
	std::list < std::pair<std::shared_ptr<All_Buildings_Units>, char> > pending_list;

	JSON j;
	while (t < 1000 && ready_units != modified_list.size())
	{
		Resources::minerals += mineral_distribution * 7;
		Resources::gas += gas_distribution * 35;
		if (Resources::energy < 1000000)
		{
			Resources::energy += 5625;
			Resources::energy > 1000000 ? Resources::energy = 1000000 : Resources::energy = Resources::energy;
		}




		if (!pending_list.empty())
		{


			for (auto it : pending_list)
			{

				if (chrono_boost && it.first->Is_Chrono_Boost_Activated())
				{
					it.first->decrement_time_with_chrono();
					/*if (!chrono_boost)
					{
						delay_in_chrono++;
					}
					*/
				}
				else
				{
					it.first->decrement_time();
				}
			}

			pending_list.sort([](const std::pair<std::shared_ptr<All_Buildings_Units>, char>&rhs, const std::pair<std::shared_ptr<All_Buildings_Units>, char> &lhs)
			{
				return rhs.first->return_remaining_time() < lhs.first->return_remaining_time();
			});


			auto begin = pending_list.begin();



			while (begin != pending_list.end())
			{



				if (begin->first->return_remaining_time() != 0)
				{

					break;
					break;

				}


				else
				{


					ready_units++;
					std::cout << std::endl << std::endl;
					if (print)
					{
						Event event;
						event.type = "build-end";
						event.target_building = begin->first->return_name();
						event.target_ID = begin->first->return_ID();
						event.producer_ID = begin->first->Producer_ID();
						j.push_back(event);

						event_count++;
					}

					switch (begin->second)

					{
					case 'u':
					{


						Prepared_Objects::unit_map.emplace(begin->first->return_name(), begin->first);
						if (begin->first->return_name() == "probe")
						{
							Resources::workers++;
						}


						begin = pending_list.erase(begin);
					}
					std::cout << std::endl << std::endl;
					break;
					case 'o':
					{
						Prepared_Objects::building_map.emplace(begin->first->return_name(), begin->first);

						if (begin->first->return_name() == "pylon")
						{
							Resources::supply += 8;
							total_supply += 8;
						}
						if (begin->first->return_name() == "assimilator")
						{
							assimilator_count++;
							//if (assimilator_count < 2)
							if (Resources::workers - (3 * assimilator_count) > 0)
								gas_distribution += 3;
						}


						begin = pending_list.erase(begin);
					}
					break;
					case 'b':
					{
						Prepared_Objects::builder_map.emplace(begin->first->return_name(), begin->first);

						if (begin->first->return_name() == "nexus")
						{
							nexus_count++;
							Resources::supply += 10;
							total_supply += 10;
						}

						begin = pending_list.erase(begin);
					}
					break;
					default:
					{
						std::cout << "Something is wrong!" << std::endl;
						exit(1);

					}

					}

				}


			}

		}









		if (!chrono_boost && Resources::energy >= 250000)
		{
			std::list< std::shared_ptr<All_Buildings_Units> > builder_list;
			for (auto element : Prepared_Objects::builder_map)
			{
				builder_list.push_back(element.second);
			}
			builder_list.sort([](const std::shared_ptr<All_Buildings_Units>&a, const std::shared_ptr<All_Buildings_Units> &b) { return a->return_time_to_get_free() > b->return_time_to_get_free(); });
			auto first_builder = builder_list.begin();
			if ((*first_builder)->return_time_to_get_free())
			{
				(*first_builder)->Activate_Chrono_Boost();
				chrono_boost = true;
				Resources::energy -= 250000;
				action_count++;
				chrono_target = *first_builder;
				if (print)
				{
					Event event;
					event.type = "chronoboost";
					event.producer_ID = 1;
					event.target_building = chrono_target->return_name();
					event.target_ID = chrono_target->return_ID( );
					j.push_back(event);
					event_count++;
				}
			}
	

		}





		/*if (!delay_in_chrono && !chrono_boost && Resources::energy >= 250000 && !pending_list.empty())
		{
			
			std::list< std::shared_ptr<All_Buildings_Units> > unit_list;
			
			for (auto iter = pending_list.begin(); iter != pending_list.end(); ++iter)
			{
				if (iter->second == 'u')
				{
					unit_list.push_back(iter->first);
				}
			}
			if (!unit_list.empty())
			{
				unit_list.sort([](const std::shared_ptr<All_Buildings_Units>&a, std::shared_ptr<All_Buildings_Units> &b) {return a->return_remaining_time() > b->return_remaining_time(); });

				Resources::energy -= 250000;
				auto iter_chrono = unit_list.begin();
				/*for (std::size_t i = 0; i < pending_list.size() - 1; ++i)
				{
					//	std::cout<<"Is error here"<<std::endl;
					iter_chrono++;
				}
				
				if (print)
				{
					Event event;
					event.type = "chronoboost";
					event.producer_ID = 1;
					auto Target_Info = (*iter_chrono)->Return_Builder();
					event.target_building =Target_Info.builder_name ;
					event.target_ID = Target_Info.builder_ID;
					j.push_back(event);
					event_count++;
				}
				chrono_boost = (*iter_chrono)->Activate_Chrono_Boost();
			}
			//	std::cout << "No error in chrono!" << std::endl;
		}

		*/
		if (!action_count)
		{

			auto iter = modified_list.begin();

			//std::cout << "Why" << std::endl;
			if (remaining_units > 0)
			{
				if (delay)
				{
					delay--;
				}

				/*	for (int x = 0; x < i;x++)
					{

						iter++;
					}
				*/

				iter += i;
			//	std::cout << "Value of i is: " << i << std::endl;
				//std::cout << iter->second << std::endl;
				//std::cout << "Is it here" << std::endl;
				if (!is_i_same)
				{
					/*std::cout<<"Error at this point"<<std::endl;
					std::cout<<"Here the error lies"<<std::endl;
					std::cout << "Name is : " << iter->second << std::endl; */
					info = Return_Data(iter->second);
				//	info.Display_Data();
					/*	info.Display_Data();
						char response;
						std::cin >> response;
						std::cout<<"Confirmed error lies here"<<std::endl;
						*/
				}


				if (!delay && Resources::minerals >= info.req_minerals&& Resources::gas >= info.req_gas&& Resources::supply >= info.req_supply)
				{
					/*std::cout<<"We make it till here guys!"<<std::endl;
					std::cout << "Yeah here lies the errorrrrrr~" << std::endl; */

					switch (iter->first)
					{
					case 'u':
					{
						/*std::cout<<"We enter the units section!"<<std::endl;
						std::cout<<"Name of unit is : "<<iter->second<<std::endl; */
						std::string required_builder = info.dependencies.builder_name;
						std::string building_dependency = info.dependencies.building_dependency;
						bool dependency_met;
						if (building_dependency == "")
						{
							dependency_met = true;
						}
						else
						{
							if (Prepared_Objects::building_map.find(building_dependency) != Prepared_Objects::building_map.end())
							{
								dependency_met = true;
							}
							else
							{
								dependency_met = false;
								auto b_dependency = std::find_if(pending_list.begin(), pending_list.end(), [building_dependency](std::pair<std::shared_ptr<All_Buildings_Units>, char>&req_dependency) {  return building_dependency == req_dependency.first->return_name(); });
								delay = b_dependency->first->return_remaining_time();
							}

						}


						auto iter_builder = Prepared_Objects::builder_map.find(required_builder);
						if (dependency_met && iter_builder != Prepared_Objects::builder_map.end())
						{
							if (iter_builder->second->Building_Status())
							{
								pending_list.emplace_back(std::make_shared<Units>(iter->second, iter_builder->second, info.req_time), 'u');
								i++;
								if(print)
								{
								Event event;
								event.type = "build-start";
								event.target_building = iter->second;
								event.producer_ID = iter_builder->second->return_ID();

								j.push_back(event);
								event_count++;
								}
								is_i_same = false;
							/*	if (t == 50)
								{
									std::cout << "Unit Name " << iter->second;
									std::cout << "Is chronoboost activated on builder: " << iter_builder->second->Is_Chrono_Boost_Activated();
									std::cout << "ID of Builder: " << iter_builder->second->return_ID();
									std::cout << "Is chrono boost activated: " << chrono_boost << std::endl;
							
									char response;
									std::cin >> response;
								}
								*/
							}
							else
							{

								delay = iter_builder->second->return_time_to_get_free();
							}
						}
						else if (dependency_met)
						{

							auto iter_builder = std::find_if(pending_list.begin(), pending_list.end(), [required_builder](std::pair<std::shared_ptr<All_Buildings_Units>, char>&builder) {  return required_builder == builder.first->return_name(); });
							delay = iter_builder->first->return_remaining_time();
						}
					}
					break;

					case 'b':
					{
						if (iter->second == "nexus")
						{
							pending_list.emplace_back(std::make_shared<Builder>(iter->second, info.req_time), 'b');
							i++;
							if(print)
							{
							Event e;
							e.type = "build-start";
							e.target_building = "nexus";
							e.producer_ID = 2;
							j.push_back(e);
							event_count++;
							}
							is_i_same = false;
						}
						else
						{
							std::string dependency = info.dependencies.building_dependency;
							auto iter_dependency = Prepared_Objects::building_map.find(dependency);
							if (iter_dependency != Prepared_Objects::building_map.end())
							{
								pending_list.emplace_back(std::make_shared<Builder>(iter->second, info.req_time), 'b');
								i++;
								if (print)
								{
								Event e;
								e.type = "build-start";
								e.target_building = iter->second;
								e.producer_ID = 2;
								j.push_back(e);
								event_count++;
								}
								is_i_same = false;
							}
							else
							{
								auto iter_dependency = std::find_if(pending_list.begin(), pending_list.end(), [dependency](std::pair<std::shared_ptr<All_Buildings_Units>, char>& p) {return dependency == p.first->return_name();  });
								delay = iter_dependency->first->return_remaining_time();
							}
						}
					}
					break;
					case 'o':
					{

						if (iter->second == "pylon" || iter->second == "assimilator")
						{
							pending_list.emplace_back(std::make_shared<Buildings>(iter->second, info.req_time), 'o');
							i++;
							if (print)
							{
							Event e;
							e.type = "build-start";
							e.target_building = iter->second;
							e.producer_ID = 2;
							j.push_back(e);
							event_count++;
							}
							is_i_same = false;
						}
						else if (info.dependencies.builder_dependency != "" && info.dependencies.building_dependency == "")
						{

							std::string builder_dependency = info.dependencies.builder_dependency;

							auto iter_builder = Prepared_Objects::builder_map.find(builder_dependency);
							if (iter_builder != Prepared_Objects::builder_map.end())
							{
								pending_list.emplace_back(std::make_shared<Buildings>(iter->second, info.req_time), 'o');
								i++;
								if(print)
								{
								Event e;
								e.type = "build-start";
								e.target_building = iter->second;
								e.producer_ID = 2;
								j.push_back(e);
								event_count++;
								}
								is_i_same = false;
							}
							else
							{
								auto iter_builder = std::find_if(pending_list.begin(), pending_list.end(), [builder_dependency](std::pair<std::shared_ptr<All_Buildings_Units>, char>&p) {return builder_dependency == p.first->return_name(); });
								delay = iter_builder->first->return_remaining_time();
							}
						}
						else if (iter->second == "forge" || (info.dependencies.building_dependency != "" && info.dependencies.builder_dependency == ""))
						{

							//std::cout << "Okwe make it till here in the beg of if loop" << std::endl;
							std::string dependency = info.dependencies.building_dependency;
							//info.Display_Data();
							auto iter_dependency = Prepared_Objects::building_map.find(dependency);
							//std::cout<<"Okwe make it till here in the beg of if loop"<<std::endl;

							if (iter_dependency != Prepared_Objects::building_map.end())
							{
								//	std::cout<<"Okwe make it till here in the beg of if loop"<<std::endl;
								pending_list.emplace_back(std::make_shared<Buildings>(iter->second, info.req_time), 'o');
								i++;
								if (print)
								{
								Event e;
								e.type = "build-start";
								e.target_building = iter->second;
								e.producer_ID = 2;
								j.push_back(e);
								event_count++;
								}
								is_i_same = false;
								//	std::cout<<"Okwe make it till here AS WELL "<<std::endl;
							}
							else
							{
								//std::cout << "Are we here?" << std::endl;
								//std::cout << "Dependency is " << dependency << std::endl;
								auto iter_dependency = std::find_if(pending_list.begin(), pending_list.end(), [dependency](std::pair<std::shared_ptr<All_Buildings_Units>, char>& p) {return dependency == p.first->return_name();  });
								//std::cout << "Calculating delay: " << std::endl;
							/*	for (auto it : modified_list)
								{
									std::cout << "Element " << it.second << std::endl;
								}
								*/
								delay = iter_dependency->first->return_remaining_time();
								//std::cout << "delay is : " << delay << std::endl;
							}
						}
					}
					break;
					default:
					{

					}

					}

					if (!delay)
					{
						Resources::minerals -= info.req_minerals;
						Resources::gas -= info.req_gas;
						Resources::supply -= info.req_supply;
							

						remaining_units--;

					}


				}



				else
				{
					/*
					if (info.req_minerals > Resources::minerals && info.req_gas > Resources::gas)
					{
						gas_distribution = floor_function((2 / 3)*Resources::workers);
						mineral_distribution = Resources::workers - gas_distribution;
						if (assimilator_count == 1)
						{
							if (gas_distribution > 3)
							{
								int remainder = gas_distribution - 3;
								gas_distribution = 3;
								mineral_distribution += remainder;
							}
						}
						else if (assimilator_count == 2)
						{
							if (gas_distribution > 6)
							{
								int remainder = gas_distribution - 6;
								gas_distribution = 6;
								mineral_distribution += remainder;
							}

						}
					}
					else if (info.req_minerals > Resources::minerals)
					{
						mineral_distribution = Resources::workers;
						gas_distribution = 0;
					}
					else if (info.req_gas > Resources::gas)
					{
						assimilator_count == 1 ? gas_distribution = 3 : gas_distribution = 6;
						mineral_distribution = Resources::workers - gas_distribution;
					}

					*/
				 if (!delay)
					{
						
					 auto original_gas_distribution = gas_distribution;
						if (assimilator_count)
						{
						auto t_mineral = (info.req_minerals-Resources::minerals)/7;
						auto t_gas =(info.req_gas - Resources::gas)/35;
							if (t_mineral>t_gas)
							{
								gas_distribution =3;
							}
							else if (t_gas> t_mineral)
							{
								(assimilator_count==1) ? gas_distribution =3: gas_distribution=6;
							}

						}

						if (original_gas_distribution != gas_distribution)
						{
							j.print_worker_distribution(t, Resources::workers - gas_distribution, gas_distribution, total_supply);
					    }
				 
				    }
					
					is_i_same = true;
				}
			}

		}

		mineral_distribution = Resources::workers - gas_distribution;

		/*if (delay_in_chrono)
		{
			delay_in_chrono--;
		}
		*/

		if (chrono_target)
		{
			auto chrono_time = chrono_target->Decrement_Chrono_Time();
			
			if (!chrono_time)
			{
				
				
				chrono_boost = false;
				chrono_target = nullptr;
			}
			

		}
		if (action_count)
		{
			action_count--;
		}
		if (print && event_count)
		{
				j.print(t, mineral_distribution, gas_distribution, total_supply, modified_list.size() - ready_units);
				event_count = 0;
		}
			
		t++;

	}

	//	std::cout << "Simulation ended in time: " << t << std::endl;
	//	Resources::Display_Resources();
	Resources::Reset_Resources();
	//std::cout << "After Reset: " << std::endl;

	Prepared_Objects::Reset_Containers();
	return t;

}