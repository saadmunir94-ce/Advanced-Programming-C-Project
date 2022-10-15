#pragma once
#include "Main_Classes.h"
#include<map>
#include<utility>

class Prepared_Objects
{
public:
	static std::multimap<std::string, std::shared_ptr<All_Buildings_Units>>  builder_map;
	static std::multimap<std::string, std::shared_ptr<All_Buildings_Units>> building_map;
	static std::multimap<std::string, std::shared_ptr<All_Buildings_Units>> unit_map;
	/*All objects stored have remaining time of zero as they are already built*/
	static void Reset_Containers();

};
inline int floor_function(double value)
{
	int return_integer;
	double fraction = value - int(value);
	if (fraction >= 0.5)
	{
		return_integer = int(value);
		return_integer++;
	}
	else
	{
		return_integer = int(value);
	}

	return return_integer;
}