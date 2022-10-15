
#include "Main_Classes.h"

long Resources::minerals = 500;
long Resources::gas = 0;
int Resources::supply = 4;
int Resources::workers = 6;
long Resources::energy = 0;
long All_Buildings_Units::count = 0;

void Resources::Display_Resources()
{

	std::cout << "Current Minerals: " << minerals << std::endl;
	std::cout << "Current Gas: " << gas << std::endl;
	std::cout << "Current Supply: " << supply << std::endl;
	std::cout << "Current Energy: " << energy << std::endl;
	std::cout << "Available Workers: " << workers << std::endl;

}
void Resources::Reset_Resources()
{
	minerals = 500;
	gas = 0;
	supply = 4;
	workers = 6;
	energy = 0;
	//std::cout << "Reset done!" << std::endl;
}

bool Builder::Activate_Chrono_Boost()
{
	chrono_count = 21;
	is_chrono_boost_activated = true;
	return is_chrono_boost_activated;
}
long Builder::Decrement_Chrono_Time()
{
	chrono_count--;
	if (!chrono_count)
	{
		is_chrono_boost_activated = false;
	}
	return chrono_count;
}

long Units::decrement_time_with_chrono()
{
	if (remaining_time > 0)
	{
		remaining_time -= 1.5;
		producer->time_to_get_free -= 1.5;
		if (remaining_time < 0)
		{
			remaining_time = 0;
			producer->time_to_get_free = 0;
		}
	}
	/*	if (!remaining_time)
		{
			producer = nullptr;
		}
		*/
	return remaining_time;
}


float Units::decrement_time()
{
	if (remaining_time > 0)
	{
		remaining_time--;
		producer->time_to_get_free--;
		if (remaining_time < 0)
		{
			remaining_time = 0;
			producer->time_to_get_free = 0;
		}
	}
	/*if (!remaining_time)
	{
		producer = nullptr;
	}
	*/
	return remaining_time;
}

bool Units::Is_Chrono_Boost_Activated()
{
	return producer->Is_Chrono_Boost_Activated();
}
std::shared_ptr<All_Buildings_Units> Units:: Release_Builder()
{
    if (producer)
	{
		auto copy = producer;
		producer = nullptr;
		return copy;
	}
	else
	{
		return nullptr;
	}
	
	
}