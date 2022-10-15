#include "Valid_Items_Class.h"
#include "General_Declarations.h"
#include "Enumerations.h"
#include<vector>
#include<list>
#include<utility>

long Make_Generation_Valid(std::list<std::pair<int, std::vector<std::pair<char, std::string>>>>& generation)
{
	auto iter = generation.begin();
	while (iter != generation.end())
	{
		bool valid = is_BuildList_Valid(iter->second);
		if (!valid)
		{
			iter = generation.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return generation.size();
}