#pragma once
#include<string>
#include<deque>
#include<fstream>
struct Event
{
	std::string type;
	std::string target_building;
	long target_ID;
	long producer_ID;
};
class JSON
{
private:
	std::deque<Event> event_deque;
	std::ofstream json_output;
public:
	JSON()
	{   }
	void push_back(Event);
	void print(bool);
	void print(const int&, const int&, const int&, const int&, int);
	void print_worker_distribution (const int&,const int&, const int&, const int&);
};
