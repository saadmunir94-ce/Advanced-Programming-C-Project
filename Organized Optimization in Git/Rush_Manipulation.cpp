#include<iostream>
#include<cstdlib>
#include<list>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include "General_Declarations.h"
std::pair<int,std::vector<std::pair<char,std::string>>> Rush_Manipulation(std::list<std::pair<int, std::vector<std::pair<char, std::string> > > > & possible_builds, std::string unit_name, int time_limit)
{
	std::pair<int, std::vector<std::pair<char, std::string> > > best_build_list;
	best_build_list.first = 0;
	int count = 0;
	auto iter = possible_builds.begin();
	while (iter != possible_builds.end())
	{
		auto u_count = std::count_if(iter->second.begin(), iter->second.end(), [unit_name](std::pair<char, std::string>& a) { return a.second == unit_name;   });
		if (!u_count)
		{
			iter = possible_builds.erase(iter);
		}
		else
		{
			iter->first = u_count;
			auto time_taken = forward_simulation(iter->second,false);
			if (time_taken > std::size_t( 1.16 * time_limit) )
			{
				iter = possible_builds.erase(iter);
			}
			else
			{
				if (time_taken <= time_limit)
				{
					if (u_count > best_build_list.first)
					{
						best_build_list.second = iter->second;
						best_build_list.first = u_count;
					}

				}
				iter++;
			}
		}
	}
	return best_build_list;
}
bool Are_Equal(const std::pair<int, std::vector<std::pair<char, std::string> > >& b1, const std::pair<int, std::vector<std::pair<char, std::string> > >& b2)
{
	return std::equal(b1.second.begin(), b1.second.end(), b2.second.begin(), b2.second.end(), [](const std::pair<char, std::string>&a, const std::pair<char, std::string>&b) {return a.second == b.second; } );
}


long Rush_Sort_List(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > &possible_builds)
{
	possible_builds.sort( [](const std::pair<int, std::vector<std::pair<char, std::string> > >& a, const std::pair<int, std::vector<std::pair<char, std::string> > >& b) {return a.first > b.first;} );
	//possible_builds.unique([](const std::pair<int, std::vector<std::pair<char, std::string> > >& a, const std::pair<int, std::vector<std::pair<char, std::string> > >& b) {return a.first == b.first;});
	//possible_builds.unique(Are_Equal);
	return possible_builds.size();

}