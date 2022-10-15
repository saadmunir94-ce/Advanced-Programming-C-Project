#pragma once
#include<set>
#include<vector>
#include<string>
class Check_List
{
public:
	static std::multiset<std::string> builder_list;
	static std::multiset<std::string>unit_list;
	static std::multiset<std::string> building_list;
	static void Reset()
	{
		builder_list.clear();
		builder_list = { "nexus" };
		unit_list.clear();
		unit_list = { "probe","probe","probe","probe","probe","probe" };
		building_list.clear();
	}

};

bool is_BuildList_Valid(std::vector<std::pair<char,std::string>>& );
