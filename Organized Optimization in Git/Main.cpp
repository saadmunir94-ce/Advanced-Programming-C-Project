#include "All_Objects.h"
#include "Valid_Items_Class.h"
#include "General_Declarations.h"
#include "Enumerations.h"
#include<iostream>
#include<cstdlib>
#include<list>
#include "JSON.h"
#include<fstream>
#include<sstream>
#include "Distance.h"
std::vector<std::string> All_Objects::All_Objects_List = { "probe","pylon","assimilator","zealot","gateway","mothership","forge","stalker","cybernetics_core","high_templar","dark_templar","photon_cannon","sentry","warp_prism","robotics_facility","twilight_council","stargate","phoenix","immortal","observer","void_ray","robotics_bay","colossus","templar_archives","dark_shrine","fleet_beacon","carrier","nexus" };
void All_Objects::Reset_Object_List()
{
	All_Objects_List.clear();
	All_Objects_List = { "probe","pylon","assimilator","zealot","gateway","mothership","forge","stalker","cybernetics_core","high_templar","dark_templar","photon_cannon","sentry","warp_prism","robotics_facility","twilight_council","stargate","phoenix","immortal","observer","void_ray","robotics_bay","colossus","templar_archives","dark_shrine","fleet_beacon","carrier","nexus" };

}


int main(int argc, char** argv)
{
	srand(19081994);
	std::list<std::pair<int,std::vector< std::pair<char, std::string> > > > old_generation;
	std::list<std::pair<int, std::vector< std::pair<char, std::string> > > > new_generation;
	long N = 10000;
	std::cout << "Argv[1] is " << argv[1] << std::endl;
	
	Generate_Search_Space(old_generation, N,argv[2]);
	int count = 1;
	auto g_size = old_generation.size();
	int unsuccessful_attempt = 0;
	std::string command = argv[1];
	std::string unit_name = argv[2];
	long requirement = 0;
	std::stringstream geek(argv[3]);
	geek >> requirement;
	std::pair<int, std::vector<std::pair<char, std::string> > > best_build_list;
	if (command == "rush")
	{
		best_build_list.first = 0;
	}
	else if (command == "push")
	{
		best_build_list.first = 1000;
	}
	
	while (unsuccessful_attempt < 7 && g_size)
	{
		std::pair<int, std::vector<std::pair<char, std::string> > > b_list;
		if (count % 2)
		{
		  b_list = Simulate_Generation(command, unit_name, requirement, old_generation);
		  Create_Generation(old_generation, new_generation);
		  std::cout << "New generation size before validation is: " << new_generation.size() << std::endl;
		  std::cout << "Size after validation is : " << Make_Generation_Valid(new_generation) << std::endl;
		  g_size = new_generation.size();
		  old_generation.clear();
		}
		else
		{
			b_list = Simulate_Generation(command, unit_name, requirement, new_generation);
			Create_Generation(new_generation, old_generation);
			std::cout << "New generation size before validation is: " << old_generation.size() << std::endl;
			std::cout << "Size after validation is : " << Make_Generation_Valid(old_generation) << std::endl;
			g_size = old_generation.size();
			new_generation.clear();
		}
		count++;
		std::cout << "Count is : " <<count<<std::endl;
		/*char response;
		std::cin >> response;*/
		if (command == "rush")
		{
			std::cout << "we are in rush" << std::endl;
			if (b_list.first > best_build_list.first)
			{
				best_build_list = b_list;
				unsuccessful_attempt = 0;
			}
			else
			{
				unsuccessful_attempt++;
			}
			std::cout << "We end rush" << std::endl;
		}
		else
		{
			if (b_list.first < best_build_list.first)
			{
				best_build_list = b_list;
				unsuccessful_attempt = 0;
			}
			else
			{
				unsuccessful_attempt++;
			
			}
		}
		
	}
	std::cout << "Best buildlist has created: " << best_build_list.first << " zealots: " << std::endl;
	std::cout << "Unsuccessful counts is : " << unsuccessful_attempt << std::endl;
	std::cout << "G_size is : " << g_size << std::endl;
	system("pause");
	return 0;
}
