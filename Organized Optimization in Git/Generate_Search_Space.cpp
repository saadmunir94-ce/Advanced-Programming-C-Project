#include<list>
#include<vector>
#include "Enumerations.h"
#include "Valid_Items_Class.h"
#include "All_Objects.h"
#include<iostream>
#include<cstdlib>

void Generate_Search_Space(std::list<std::pair<int,std::vector< std::pair<char, std::string> > > > & possible_builds, long N,std::string target_name)
{
	
	for (long i = 0; i < N; ++i)
	{
		Valid_Items_Class::ResetEverything();
		std::vector< std::pair<char, std::string> > build_list;
		build_list.emplace_back('u', "probe");
		build_list.emplace_back('u', "probe");
		Valid_Items_Class::Change_Supply(-2);
		while (build_list.size() < 20)
		{
			auto list_size = All_Objects::All_Objects_List.size();
			auto rand_no = rand() % list_size;
			std::string candidate = All_Objects::All_Objects_List[rand_no];
			Valid_Items_Class::Insert_Item_Func(candidate, build_list);
			if (candidate == "nexus"&& target_name != "nexus")
			{
				All_Objects::All_Objects_List.pop_back();
			}
		}
		possible_builds.emplace_back(0,build_list);
	}

}