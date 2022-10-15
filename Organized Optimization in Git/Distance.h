#pragma once
#include<vector>
#include<list>
#include<utility>
#include<string>

struct Distance
{
	int index_1;
	int index_2;
	long dist;

	Distance (int i_1, int i_2, long d): index_1(i_1), index_2(i_2),dist(d)
	{      }
};

void Find_Best_Pair(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > &, std::vector<std::pair<char,std::string>>&, std::vector<std::pair<char,std::string>>&);
void Produce_Child(std::vector<std::pair<char, std::string> >&, std::vector<std::pair<char, std::string> >&, std::vector<std::pair<char, std::string> >&);
void Create_Generation(std::list<std::pair<int, std::vector< std::pair<char, std::string> > > >&, std::list<std::pair<int, std::vector< std::pair<char, std::string> > > >&);