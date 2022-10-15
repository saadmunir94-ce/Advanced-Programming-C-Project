#pragma once
#include<vector>
#include<list>
#include<utility>
#include<string>
#include<algorithm>
void Generate_Search_Space(std::list<std::pair<int, std::vector< std::pair<char, std::string> > > > &, long,std::string );
int forward_simulation(std::vector<std::pair<char, std::string> >&, bool print = true);
std::pair<int,std::vector<std::pair<char,std::string>>> Rush_Manipulation(std::list<std::pair<int, std::vector<std::pair<char, std::string> > > > &, std::string, int);
long Rush_Sort_List(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > &);
bool Are_Equal(const std::pair<int, std::vector<std::pair<char, std::string> > >&, const std::pair<int, std::vector<std::pair<char, std::string> > >&);
std::pair<int,std::vector<std::pair<char,std::string>>> Push_Manipulation(std::list<std::pair<int, std::vector<std::pair<char, std::string> > > > &, std::string, int);
long Push_Sort_List(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > &);
void Kill(std::list<std::pair<int, std::vector< std::pair<char, std::string> > > > &, std::string);

std::pair<int, std::vector < std::pair<char, std::string> > > Simulate_Generation(std::string, std::string, int, std::list<std::pair<int, std::vector<std::pair<char, std::string> > > >&);
long Make_Generation_Valid(std::list<std::pair<int, std::vector<std::pair<char, std::string>>>>&);