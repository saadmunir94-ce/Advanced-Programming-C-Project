#include "Enumerations.h"
#include "Data.h"
#include "Main_Classes.h"
#include "Prepared_Objects.h"
#include "JSON.h"
#include "Check_Validity.h"
#include<chrono>
#include<vector>

char Generate_Obj_Type(std::string);
int forward_simulation(std::vector<std::pair<char, std::string> >&,bool print=true );
int main(int argc, char**argv)
{
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	std::ifstream build_file(argv[2]);
	std::vector<std::pair<char,std::string>> buildlist;
	
	std::string input;

	while (build_file >> input)
	{
		char type = Generate_Obj_Type(input);
		/*std::cout << "input is : " << input<<std::endl; */
		buildlist.emplace_back(type, input);
	}
	for (auto it : buildlist)
	{
		std::cout << "Element: " << it.second << std::endl;
		std::cout << "Element Type: " << it.first << std::endl;
	}
	build_file.close();
	bool valid = is_BuildList_Valid(buildlist);
	JSON j;
	j.print(valid);
	if (valid)
	{

		auto time_taken = forward_simulation(buildlist);
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
		std::cout << "Time taken for buildlist is : " << time_taken << std::endl;
		std::cout << "Duration for checking buildlists is : " << duration << " milliseconds " << std::endl;
	}
	else
	{
		std::cout << "BuildList is invalid" << std::endl;
	}

	system("pause");
	return 0;
}