#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include "General_Declarations.h"
std::pair<int, std::vector<std::pair<char, std::string>>> Push_Manipulation(std::list<std::pair<int, std::vector<std::pair<char, std::string> > > > & possible_builds, std::string unit_name, int min_target)
{
	std::pair<int, std::vector<std::pair<char, std::string>> > best_build_list;
	best_build_list.first = 1000;
	auto iter = possible_builds.begin();
	while (iter != possible_builds.end())
	{
		auto u_count = std::count_if(iter->second.begin(), iter->second.end(), [unit_name](std::pair<char, std::string>& a) { return a.second == unit_name;   });
		if (u_count < min_target)
		{
			iter = possible_builds.erase(iter);
		}
		else
		{
			
			auto time_taken = forward_simulation(iter->second, false);
			if (time_taken >= 1000)
			{
				iter = possible_builds.erase(iter);
			}
			else
			{
				iter->first = time_taken;
				if (time_taken < best_build_list.first)
				{
					best_build_list.second = iter->second;
					best_build_list.first = iter->first;
				
				}
				iter++;
			}
			
		}
	}
	return best_build_list;
}

long Push_Sort_List(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > & possible_builds)
{
	possible_builds.sort([](const std::pair<int, std::vector<std::pair<char, std::string> > >& a, const std::pair<int, std::vector<std::pair<char, std::string> > >& b) {return a.first < b.first;});
	//possible_builds.unique([](const std::pair<int, std::vector<std::pair<char, std::string> > >& a, const std::pair<int, std::vector<std::pair<char, std::string> > >& b) {return a.first == b.first;});
	possible_builds.unique(Are_Equal);
	return possible_builds.size();


}