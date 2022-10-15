#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<memory>

struct Builder_Data
{
	std::string builder_name;
	long builder_ID;

	Builder_Data()
	{
		builder_name = "probe";
		builder_ID = 2;
	}
	Builder_Data(std::string b_name, long ID) : builder_name(b_name), builder_ID(ID)
	{

	}

};

class Resources
{
public:
	static long minerals;
	static long gas;
	static int supply;
	static int workers;
	static long energy;
	static void Display_Resources();

	static void Reset_Resources();


};

class Units;
class All_Buildings_Units
{
protected:
	std::string name;
	static long count;
	float remaining_time;
	long ID;
	float time_to_get_free;
	bool is_object_free;
	bool is_chrono_boost_activated;
	int chrono_count;
	std::string type;

	All_Buildings_Units()
	{
		ID = ++count;
		time_to_get_free = 0;
		is_object_free = true;
		is_chrono_boost_activated = false;
		chrono_count = 0;
	}
public:

	virtual void my_func() = 0;
	std::string return_name()
	{
		return name;
	}
	long return_ID()
	{
		return ID;
	}
	float return_remaining_time()
	{
		return remaining_time;
	}
	virtual float decrement_time()
	{
		if (remaining_time > 0)
		{
			remaining_time--;
			if (remaining_time < 0)
			{
				remaining_time = 0;
			}
		}
		return remaining_time;
	}
	std::string return_type()
	{
		return type;
	}
	friend class Prepared_Objects;
	virtual long Producer_ID()
	{
		return 2;
	}
	virtual Builder_Data Return_Builder()
	{
		return Builder_Data();
	}
	

	virtual float return_time_to_get_free()
	{
		return time_to_get_free;
	}
	virtual bool Building_Status()
	{
		return is_object_free;
	}
	virtual bool Activate_Chrono_Boost()
	{
		return false;
	}
	virtual bool Is_Chrono_Boost_Activated()
	{
		return is_chrono_boost_activated;
	}

	virtual long Decrement_Chrono_Time()
	{
		return 0;
	}

	virtual long decrement_time_with_chrono()
	{
		return 0;
	}
	virtual std::shared_ptr<All_Buildings_Units> Release_Builder( )
	{
		return nullptr;
	}
	friend class Units;
};
class Buildings : public All_Buildings_Units
{
	/*private:
		Buildings(std::string n)
		{
			name = n;
			remaining_time = 0;
			type = "Buildings";
		}
		*/

protected:
	Buildings()
	{

	}

public:
	Buildings(std::string n, int t)
	{
		name = n;
		remaining_time = t;
		type = "Buildings";
	}
	void my_func()
	{

	}

};
class Builder : public Buildings
{
private:
	Builder()
	{

	}
public:
	Builder(std::string n)
	{
		name = n;
		remaining_time = 0;
		type = "Builder";
	}

	Builder(std::string n, int t)
	{
		name = n;
		remaining_time = t;
		type = "Builder";

	}

	float return_time_to_get_free()
	{
		return time_to_get_free;
	}
	bool Building_Status()
	{
		return (time_to_get_free == 0) ? true : false;
	}
	bool Activate_Chrono_Boost();
	long Decrement_Chrono_Time();

};
class Units : public All_Buildings_Units
{
private:
	std::shared_ptr<All_Buildings_Units> producer;
public:
	Units(std::string n)
	{
		name = n;
		remaining_time = 0;
		producer = 0;
		type = "Units";

	}

	Units(std::string n, std::shared_ptr<All_Buildings_Units> p, int t)
	{
		producer = p;
		name = n;
		remaining_time = t;
		type = "Units";
		producer->time_to_get_free = t;
	}
	void my_func()
	{

	}
	/*create a Free_Builder Function depending upon the implementation*/

	Builder_Data Return_Builder()
	{
		return Builder_Data(producer->return_name(), producer->return_ID());
	}
	std::shared_ptr<All_Buildings_Units> Release_Builder();
	
	float decrement_time();
	long decrement_time_with_chrono();
	long Producer_ID()
	{
		return producer->return_ID();
	}
	bool Is_Chrono_Boost_Activated();
};



