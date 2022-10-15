#include "Enumerations.h"
#include "Valid_Items_Class.h"
#include<iostream>
std::multiset<std::string> Check_List::builder_list = { "nexus" };
std::multiset<std::string> Check_List::unit_list = { "probe","probe","probe","probe","probe","probe" };
std::multiset<std::string> Check_List::building_list;



bool Valid_Items_Class::is_assimilator = false;
int Valid_Items_Class::mother_count = 0;
int Valid_Items_Class::assimilator_count = 0;
int Valid_Items_Class::total_supply = 4;
int Valid_Items_Class::nexus_count = 1;

void Valid_Items_Class::ResetEverything()
{
	is_assimilator = false;
	mother_count = 0;
	assimilator_count = 0;
	total_supply = 4;
	nexus_count = 1;
	Check_List::Reset();
}
void Valid_Items_Class::Change_Supply(int s)
{
	total_supply += s;
}

void Valid_Items_Class::Insert_Item_Func(std::string candidate, std::vector<std::pair<char, std::string>>& buildlist)
{
	

	switch (hash_it(candidate))
	{
	case probe:
	{
		if (total_supply >= 1)
		{
		
			//	std::cout << "Total_supply: " << total_supply << std::endl;

			Check_List::unit_list.insert("probe");
		    buildlist.emplace_back('u', "probe");
			total_supply -= 1;
			
			//std::cout << "supply after inserting probe is : " << total_supply << std::endl;
			//char response;
			//std::cin >> response;
			

		}
		break;
	}
	case nexus:
	{

			Check_List::builder_list.insert("nexus");
			buildlist.emplace_back('b', "nexus");
			total_supply += 10;
			nexus_count++;
		    break;

	}
	case zealot:
	{
		if (total_supply >= 2 && Check_List::builder_list.find("gateway") != Check_List::builder_list.end())
		
		{
			Check_List::unit_list.insert("zealot");
			buildlist.emplace_back('u', "zealot");
			total_supply -= 2;
			

		}
		break;

	}
	case pylon:
	{
		Check_List::building_list.insert("pylon");
		buildlist.emplace_back('o', "pylon");
		total_supply += 8;
		
		break;
	}
	case gateway:
	{

		if (Check_List::builder_list.find("nexus") != Check_List::builder_list.end() && Check_List::building_list.find("pylon") != Check_List::building_list.end())
		{
			
			Check_List::builder_list.insert("gateway");
			buildlist.emplace_back('b', "gateway");
		
		}
		

		break;
	}
	case forge:
	{

		if (Check_List::builder_list.find("nexus") != Check_List::builder_list.end() && Check_List::building_list.find("pylon") != Check_List::building_list.end())
		{
			
			Check_List::building_list.insert("forge");
			buildlist.emplace_back('o', "forge");

		}
		
		break;
	}
	case stalker:
	{
		if (is_assimilator && total_supply>=2 && Check_List::builder_list.find("gateway")!=Check_List::builder_list.end() && Check_List::building_list.find("cybernetics_core")!=Check_List::building_list.end()   )
		{
			
				Check_List::unit_list.insert("stalker");
				buildlist.emplace_back('u', "stalker");
				total_supply -= 2;
				

			

		}
		
		break;
	}
	case mothership:
	{
		if (is_assimilator && !mother_count&&total_supply>=8 && Check_List::building_list.find("fleet_beacon") != Check_List::building_list.end() &&Check_List::builder_list.find("nexus") != Check_List::builder_list.end() )
		{
			
			Check_List::unit_list.insert("mothership");
			buildlist.emplace_back('u', "mothership");
			total_supply -= 8;
			mother_count++;
			

		}

		break;
	}

	case sentry:
	{
		if (is_assimilator  && total_supply >= 2 &&Check_List::builder_list.find("gateway") !=Check_List::builder_list.end() && Check_List::building_list.find("cybernetics_core") != Check_List::building_list.end()  )
		{
			
			Check_List::unit_list.insert("sentry");
			buildlist.emplace_back('u', "sentry");
			total_supply -= 2;
		}
		break;
	}

	case assimilator:
	{

		if (assimilator_count <2 )
		{
			/*if (buildlist.size() < 18 && total_supply>=1)
			{
				buildlist.emplace_back('u', "probe");
				total_supply -= 1;
			}
			*/
			
			Check_List::building_list.insert("assimilator");
			buildlist.emplace_back('o', "assimilator");
			assimilator_count++;
			is_assimilator = true;
		}
		break;
	}

	case cybernetics_core:
	{
		if (Check_List::builder_list.find("gateway") != Check_List::builder_list.end())
		{
			
			Check_List::building_list.insert("cybernetics_core");
			buildlist.emplace_back('o', "cybernetics_core");
			

		}
		break;
	}

	case high_templar:
	{
		if (is_assimilator && total_supply >=2 && Check_List::builder_list.find("gateway") != Check_List::builder_list.end() && Check_List::building_list.find("templar_archives") != Check_List::building_list.end()  )
		{
			Check_List::unit_list.insert("high_templar");
			buildlist.emplace_back('u', "high_templar");
			total_supply -= 2;
	
		}
		break;
	}

	case dark_templar:
	{
		if (is_assimilator  && total_supply >= 2 && Check_List::builder_list.find("gateway") != Check_List::builder_list.end() && Check_List::building_list.find("dark_shrine") != Check_List::building_list.end())
		{
			
			Check_List::unit_list.insert("dark_templar");
			buildlist.emplace_back('u', "dark_templar");
			total_supply -= 2;
			
		}
		break;
	}

	case photon_cannon:
	{

		if (Check_List::building_list.find("forge") != Check_List::building_list.end())
		{
			
			Check_List::building_list.insert("photon_cannon");
			buildlist.emplace_back('o', "photon_cannon");
			
		}
		break;
	}

	case warp_prism:
	{
		if (total_supply >= 2 && Check_List::builder_list.find("robotics_facility") != Check_List::builder_list.end())
		{
			
			Check_List::unit_list.insert("warp_prism");
			buildlist.emplace_back('u', "warp_prism");
			total_supply -= 2;

		}

		break;
	}

	case robotics_facility:
	{
		if (is_assimilator && Check_List::building_list.find("cybernetics_core") != Check_List::building_list.end())
		{
			
			Check_List::builder_list.insert("robotics_facility");
			buildlist.emplace_back('b', "robotics_facility");

		}
		break;

	}

	case immortal:
	{
		if (is_assimilator && total_supply >= 4 && Check_List::builder_list.find("robotics_facility") != Check_List::builder_list.end())
		{
			
			Check_List::unit_list.insert("immortal");
			buildlist.emplace_back('u', "immortal");
			total_supply -= 4;

		}
		break;
	}

	case twilight_council:
	{

		if (is_assimilator && Check_List::building_list.find("cybernetics_core") != Check_List::building_list.end())
		{

			
			Check_List::building_list.insert("twilight_council");
			buildlist.emplace_back('o', "twilight_council");
		

		}
		break;
	}

	case observer:
	{
		if (is_assimilator && total_supply >= 1 && Check_List::builder_list.find("robotics_facility") != Check_List::builder_list.end())
		{
			
			Check_List::unit_list.insert("observer");
			buildlist.emplace_back('u', "observer");
			total_supply -= 1;

		}
		break;
	}
	case stargate:
	{
		if (is_assimilator && Check_List::building_list.find("cybernetics_core") != Check_List::building_list.end())

		{
			
			Check_List::builder_list.insert("stargate");
			buildlist.emplace_back('b', "stargate");
		

		}
		break;
	}

	case phoenix:
	{
		if (is_assimilator && total_supply >= 2 && Check_List::builder_list.find("stargate") != Check_List::builder_list.end())
		{
			
			Check_List::unit_list.insert("phoenix");
			buildlist.emplace_back('u', "phoenix");
			total_supply -= 2;
	
		}
		break;
	}

	case void_ray:
	{

		if (is_assimilator && total_supply >= 3  && Check_List::builder_list.find("stargate") != Check_List::builder_list.end())
		{

			Check_List::unit_list.insert("void_ray");
			buildlist.emplace_back('u', "void_ray");
			total_supply -= 3;
			

		}
		break;
	}

	case colossus:
	{
		if (is_assimilator  && total_supply >= 6 && Check_List::builder_list.find("robotics_facility") != Check_List::builder_list.end() && Check_List::building_list.find("robotics_bay") != Check_List::building_list.end())
		{
			
			Check_List::unit_list.insert("colossus");
			buildlist.emplace_back('u', "colossus");
			total_supply -= 6;

		}
		break;
	}

	case robotics_bay:
	{
		if (is_assimilator && Check_List::builder_list.find("robotics_facility") != Check_List::builder_list.end())
		{
			
			Check_List::building_list.insert("robotics_bay");
			buildlist.emplace_back('o', "robotics_bay");
			

		}
		break;
	}


	case templar_archives:
	{
		if (is_assimilator && Check_List::building_list.find("twilight_council") != Check_List::building_list.end())
		{
			
			Check_List::building_list.insert("templar_archives");
			buildlist.emplace_back('o', "templar_archives");
			

		}
		break;
	}

	case dark_shrine:
	{
		if (is_assimilator && Check_List::building_list.find("twilight_council") != Check_List::building_list.end())
		{
			
			Check_List::building_list.insert("dark_shrine");
			buildlist.emplace_back('o', "dark_shrine");
			
		}
		break;
	}

	case fleet_beacon:
	{
		if (is_assimilator && Check_List::builder_list.find("stargate") != Check_List::builder_list.end())
		{
			
			Check_List::building_list.insert("fleet_beacon");
			buildlist.emplace_back('o', "fleet_beacon");
			

		}
		break;
	}

	case carrier:
	{
		if (is_assimilator  && total_supply >= 6 && Check_List::builder_list.find("stargate") != Check_List::builder_list.end() && Check_List::building_list.find("fleet_beacon") != Check_List::building_list.end())
		{
			Check_List::unit_list.insert("carrier");
			buildlist.emplace_back('u', "carrier");
			total_supply -= 6;
			
		}
		break;
	}

	}
	if (buildlist.size() < 19 && total_supply == 0)
	{
		buildlist.emplace_back('o', "pylon");
		total_supply += 8;
	}
	

}

