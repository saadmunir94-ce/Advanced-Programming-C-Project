#pragma once
#include<string>
#include<iostream>
struct Producer_Plus_Dependency
{
	std::string builder_name;
	std::string builder_dependency;
	std::string building_dependency;
	Producer_Plus_Dependency()
	{
		builder_name = "";
		builder_dependency = "";
		building_dependency = "";
	}

};
struct Data
{
	int req_minerals;
	int req_gas;
	int req_time;
	int req_supply;
	Producer_Plus_Dependency dependencies;
	std::string builder; /*only for units*/
	Data()
	{

	}
	Data(int m, int g, int t) :req_minerals(m), req_gas(g), req_time(t), req_supply(0), builder("")
	{

	}
	Data(int m, int g, int t, int s, std::string b) : req_minerals(m), req_gas(g), req_time(t), req_supply(s), builder(b)
	{

	}

	Data(int m, int g, int t, int s, Producer_Plus_Dependency d) : req_minerals(m), req_gas(g), req_time(t), req_supply(s), dependencies(d)
	{

	}

	void Display_Data()
	{
		std::cout << "Required Minerals: " << req_minerals << std::endl;
		std::cout << "Required Gas: " << req_gas << std::endl;
		std::cout << "Required Time: " << req_time << std::endl;
		std::cout << "Required Supply: " << req_supply << std::endl;
		std::cout << "Producer name : " << dependencies.builder_name << std::endl;
		std::cout << "Builder Dependency: " << dependencies.builder_dependency << std::endl;
		std::cout << "Other Dependency: " << dependencies.building_dependency << std::endl;
	}
};
Data Return_Data(std::string);