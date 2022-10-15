#pragma once
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<set>
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

class Valid_Items_Class
{
public:
	static bool is_assimilator;
	static int mother_count;
	static int assimilator_count;
	static int total_supply;
	static int nexus_count;
	static void Change_Supply(int);
	static int Return_Supply()
	{
		return total_supply;
	}
	static void Insert_Item_Func(std::string, std::vector<std::pair<char, std::string> >& );
	static void ResetEverything();

};

bool is_BuildList_Valid(std::vector<std::pair<char, std::string>>&);