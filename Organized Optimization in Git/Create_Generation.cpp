#include "Distance.h"
#include"Valid_Items_Class.h"
#include<iostream>
void Create_Generation(std::list<std::pair<int, std::vector< std::pair<char, std::string> > > >& old_generation, std::list<std::pair<int, std::vector< std::pair<char, std::string> > > >& new_generation)
{
	std::vector< std::pair<char, std::string> > father;
	std::vector< std::pair<char, std::string> > mother;
	std::vector< std::pair<char, std::string> > child;
	
	while (new_generation.size() < 4 * old_generation.size())
	{
		
		Find_Best_Pair(old_generation, father, mother);
		Produce_Child(father, mother, child);
		new_generation.emplace_back(0, child);
		Valid_Items_Class::ResetEverything();
		father.clear();
		mother.clear();
		child.clear();
	}
	std::cout << "Size of new generation is : " << new_generation.size() << std::endl;
	std::cout << "Size of old generation is : " << old_generation.size() << std::endl;
}