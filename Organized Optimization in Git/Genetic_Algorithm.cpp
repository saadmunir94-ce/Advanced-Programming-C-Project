#include "Distance.h"
#include "Valid_Items_Class.h"
#include<cstdlib>
#include<iostream>
void Find_Best_Pair(std::list< std::pair<int, std::vector< std::pair<char, std::string> > > > & old_generation,std::vector<std::pair<char,std::string> >& father, std::vector<std::pair<char,std::string>>&mother)
{
	std::vector< std::vector <std::pair<char, std::string>  >  > candidates;
	std::vector<Distance> vect_dist;
	for (int i = 0; i < 4; ++i)
	{
		auto rand_no = rand() % old_generation.size();
		auto iter_first = old_generation.begin();
		for (long i = 0; i < rand_no; ++i)
		{
			iter_first++;
		}
		candidates.push_back(iter_first->second);
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int x = i + 1; x < 4; ++x)
		{
			long distance = 0;
			int l;
			if (candidates[i].size() <= candidates[x].size())
			{
				l = candidates[i].size();
			}
			else
			{
				l = candidates[x].size();
			}

			for (int count = 0; count < l; ++count)
			{
				
				if (candidates[i][count].second != candidates[x][count].second)
				{
					distance += l - count - 1;
				}
				
			}
			vect_dist.emplace_back(i, x, distance);
		}

	}
	auto dist_largest = vect_dist[0];
	
	for (int x = 1; x < vect_dist.size(); ++x)
	{
		if (vect_dist[x].dist > dist_largest.dist)
		{
			dist_largest = vect_dist[x];
		}
	}
	father = candidates[dist_largest.index_1];
	mother = candidates[dist_largest.index_2];
	
}

void Produce_Child(std::vector<std::pair<char, std::string> >& father, std::vector<std::pair<char, std::string> >& mother, std::vector<std::pair<char, std::string> >& child)
{
	int invalid_count = 0;
	std::pair<char, std::string> candidate;
	int i = 1;
	int rand_no;
	if (father.size() == mother.size())
	{
		while (child.size() < 20 && invalid_count < 20)
		{
			if (i % 2)
			{
				rand_no = rand() % father.size();
				candidate = father[rand_no];
			}
			else
			{
				rand_no = rand() % mother.size();
				candidate = mother[rand_no];
			}
			i++;
			auto original_size = child.size();
			Valid_Items_Class::Insert_Item_Func(candidate.second, child);
			if (child.size() == original_size)
			{
				invalid_count++;
			}
			else
			{
				invalid_count = 0;
			}
			
		}
	}
	else if (father.size() < mother.size())
	{
		child = father;
		while (child.size() < 20 && invalid_count < 20)
		{
			rand_no = rand() % mother.size();
			candidate = mother[rand_no];
			auto original_size = child.size();
			Valid_Items_Class::Insert_Item_Func(candidate.second, child);
			if (child.size() == original_size)
			{
				invalid_count++;
			}
			else
			{
				invalid_count = 0;
			}

		}
	}
	else
	{
		child = mother;
		while (child.size() < 20 && invalid_count < 20)
		{
			rand_no = rand() % father.size();
			candidate = father[rand_no];
			auto original_size = child.size();
			Valid_Items_Class::Insert_Item_Func(candidate.second, child);
			if (child.size() == original_size)
			{
				invalid_count++;
			}
			else
			{
				invalid_count = 0;
			}

		}
	}
}
