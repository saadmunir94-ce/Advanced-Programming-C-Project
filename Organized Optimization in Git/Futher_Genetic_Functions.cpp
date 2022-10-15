#include "Distance.h"
#include "Valid_Items_Class.h"
#include "General_Declarations.h"
#include<cstdlib>
#include<iostream>
void Kill(std::list<std::pair<int, std::vector< std::pair<char, std::string> > > > & generation, std::string command)
{
	if (command == "rush")
	{
		Rush_Sort_List(generation);
	}
	else if (command == "push")
	{
		Push_Sort_List(generation);
	}

	auto N = generation.size();
	generation.resize(std::size_t(0.15*N));
}
std::pair<int, std::vector < std::pair<char, std::string> > > Simulate_Generation(std::string command, std::string unit_name, int requirement, std::list<std::pair<int, std::vector<std::pair<char, std::string> > > >& generation)
{
	std::pair<int,std::vector< std::pair<char, std::string>>> best_build_list;
	if (command == "rush")
	{
		best_build_list = Rush_Manipulation(generation, unit_name, requirement);
	}
	else if (command == "push")
	{
		best_build_list= Push_Manipulation(generation, unit_name, requirement);

	}
	Kill(generation, command);
	return best_build_list;
}