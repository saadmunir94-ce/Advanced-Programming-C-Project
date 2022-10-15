#include "Valid_Items_Class.h"
#include "Enumerations.h"
#include<vector>
#include<list>
#include<utility>
bool is_BuildList_Valid(std::vector<std::pair<char, std::string>>&buildlist)
{

	/*for (auto it : buildlist)
	{
		std::cout << it << std::endl;
	}
	*/

	bool is_assimilator = false;
	bool valid = true;
	int mother_count = 0;
	int assimilator_count = 0;
	int total_supply = 4;

	for (auto it : buildlist)
	{
		switch (hash_it(it.second))
		{
		case probe:
		{
			if (!(total_supply >= 1))
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("probe");
				total_supply -= 1;

			}
			break;
		}
		case nexus:
		{
			Check_List::builder_list.insert("nexus");
			total_supply += 10;

			break;
		}
		case zealot:
		{
			if (!(total_supply >= 2))
			{
				return false;
			}

			else if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("zealot");
				total_supply -= 2;

			}
			break;

		}
		case pylon:
		{
			Check_List::building_list.insert("pylon");
			total_supply += 8;

			break;
		}
		case gateway:
		{

			if (Check_List::building_list.find("pylon") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::builder_list.insert("gateway");

			}

			break;
		}
		case forge:
		{
			if (Check_List::building_list.find("pylon") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("forge");

			}
			break;
		}
		case stalker:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (!(total_supply >= 2))
			{
				return false;
			}
			else
			{
				if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end())
				{
					return false;
				}
				else if (Check_List::building_list.find("cybernetics_core") == Check_List::building_list.end())
				{
					return false;
				}
				else
				{
					Check_List::unit_list.insert("stalker");
					total_supply -= 2;

				}

			}
			break;
		}
		case mothership:
		{
			if (is_assimilator == false || mother_count > 0 || (total_supply < 8))
			{
				return false;
			}
			else if (Check_List::building_list.find("fleet_beacon") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("mothership");
				total_supply -= 8;
				mother_count++;

			}

			break;
		}

		case sentry:
		{
			if (is_assimilator == false || total_supply < 2)
			{
				return false;
			}
			else if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end() || Check_List::building_list.find("cybernetics_core") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("sentry");
				total_supply -= 2;

			}
			break;
		}

		case assimilator:
		{

			if (assimilator_count > 1)
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("assimilator");
				assimilator_count++;
				is_assimilator = true;


			}
			break;
		}

		case cybernetics_core:
		{
			if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("cybernetics_core");

			}
			break;
		}

		case high_templar:
		{
			if (is_assimilator == false || total_supply < 2)
			{
				return false;
			}
			else if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end() || Check_List::building_list.find("templar_archives") == Check_List::building_list.end())
			{
				return false;

			}
			else
			{
				Check_List::unit_list.insert("high_templar");
				total_supply -= 2;

			}
			break;
		}

		case dark_templar:
		{
			if (is_assimilator == false || total_supply < 2)
			{
				return false;
			}
			else if (Check_List::builder_list.find("gateway") == Check_List::builder_list.end() || Check_List::building_list.find("dark_shrine") == Check_List::building_list.end())

			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("dark_templar");
				total_supply -= 2;


			}
			break;
		}

		case photon_cannon:
		{
			if (Check_List::building_list.find("forge") == Check_List::building_list.end())
			{
				return false;

			}
			else
			{
				Check_List::building_list.insert("photon_cannon");

			}
			break;
		}

		case warp_prism:
		{
			if (total_supply < 2 || Check_List::builder_list.find("robotics_facility") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("warp_prism");
				total_supply -= 2;

			}

			break;
		}

		case robotics_facility:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (Check_List::building_list.find("cybernetics_core") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::builder_list.insert("robotics_facility");

			}
			break;

		}

		case immortal:
		{
			if (is_assimilator == false || total_supply < 4)
			{
				return false;
			}
			else if (Check_List::builder_list.find("robotics_facility") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("immortal");
				total_supply -= 4;

			}
			break;
		}

		case twilight_council:
		{

			if (is_assimilator == false)
			{

				return false;
			}
			else if (Check_List::building_list.find("cybernetics_core") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("twilight_council");

			}
			break;
		}

		case observer:
		{
			if (is_assimilator == false || total_supply < 1)
			{
				return false;
			}
			else if (Check_List::builder_list.find("robotics_facility") == Check_List::builder_list.end())
			{
				return false;

			}
			else
			{
				Check_List::unit_list.insert("observer");
				total_supply -= 1;

			}
			break;
		}
		case stargate:
		{
			if (is_assimilator == false)

			{
				return false;
			}
			else if (Check_List::building_list.find("cybernetics_core") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::builder_list.insert("stargate");

			}
			break;
		}

		case phoenix:
		{
			if (is_assimilator == false || total_supply < 2)
			{
				return false;
			}
			else if (Check_List::builder_list.find("stargate") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("phoenix");
				total_supply -= 2;

			}
			break;
		}

		case void_ray:
		{
			if (is_assimilator == false || total_supply < 3)
			{
				return false;
			}
			else if (Check_List::builder_list.find("stargate") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("void_ray");
				total_supply -= 3;

			}
			break;
		}

		case colossus:
		{
			if (is_assimilator == false || total_supply < 6)
			{
				return false;
			}
			else if (Check_List::builder_list.find("robotics_facility") == Check_List::builder_list.end() || Check_List::building_list.find("robotics_bay") == Check_List::building_list.end())

			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("colossus");
				total_supply -= 6;

			}
			break;
		}

		case robotics_bay:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (Check_List::builder_list.find("robotics_facility") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("robotics_bay");

			}
			break;
		}


		case templar_archives:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (Check_List::building_list.find("twilight_council") == Check_List::building_list.end())
			{

				return false;
			}
			else
			{
				Check_List::building_list.insert("templar_archives");

			}
			break;
		}

		case dark_shrine:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (Check_List::building_list.find("twilight_council") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("dark_shrine");

			}
			break;
		}

		case fleet_beacon:
		{
			if (is_assimilator == false)
			{
				return false;
			}
			else if (Check_List::builder_list.find("stargate") == Check_List::builder_list.end())
			{
				return false;
			}
			else
			{
				Check_List::building_list.insert("fleet_beacon");

			}
			break;
		}

		case carrier:
		{
			if (is_assimilator == false || total_supply < 6)
			{
				return false;
			}
			else if (Check_List::builder_list.find("stargate") == Check_List::builder_list.end() || Check_List::building_list.find("fleet_beacon") == Check_List::building_list.end())
			{
				return false;
			}
			else
			{
				Check_List::unit_list.insert("carrier");
				total_supply -= 6;

			}
			break;
		}

		}
	}
	Check_List::Reset();
	return valid;
}
