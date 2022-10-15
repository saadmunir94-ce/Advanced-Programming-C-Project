#include "JSON.h"
#include "Main_Classes.h"
void JSON::print(bool valid)
{

	json_output.open("Chronowith1.txt");
	json_output << "{" << std::endl << "\"game\" : " << "\"sc2-hots-protoss\"," << std::endl;
	json_output << "\"buildlistValid\" : \"" << valid<<"\"";

	if (valid)
	{
		json_output << "," << std::endl;
		json_output << "\"initialUnits\" : " << " { " << std::endl;
		json_output << "\"probe\": " << "[\"2\",\"3\",\"4\",\"5\",\"6\",\"7\"]," << std::endl;
		json_output << "\"nexus\": " << "[\"1\"]" << std::endl << "}," << std::endl;
		json_output << "\"messages\" : " << "[" << std::endl;

	}
	else
	{
		json_output << std::endl << "}" << std::endl;
	}
	json_output.close();
}

void JSON::push_back(Event e)
{
	event_deque.push_back(e);
}
void JSON::print(const int &time, const int& m_distribution, const int& g_distribution, const int& total_supply, int remaining_units)
{

	json_output.open("Chronowith1.txt", std::ios::app);
	json_output << "{" << std::endl;
	json_output << "\"time\" : " << time << "," << std::endl;
	json_output << "\"status\" : " << "{" << std::endl;
	json_output << "\"workers\" : " << "{" << std::endl;
	json_output << "\"minerals\" : " << m_distribution << "," << std::endl;
	json_output << "\"vespene\" : " << g_distribution << std::endl << "}," << std::endl;
	json_output << "\"resources\" : " << "{" << std::endl;
	json_output << "\"minerals\" : " << Resources::minerals / 10 << "," << std::endl;
	json_output << "\"vespene\" : " << Resources::gas / 100 << "," << std::endl;
	json_output << "\"supply-used\" : " << total_supply - Resources::supply << "," << std::endl;
	json_output << "\"supply\" : " << total_supply << std::endl << "}" << std::endl << "}," << std::endl;
	json_output << "\"events\" : " << "[" << std::endl;

	while (!event_deque.empty())
	{
		auto event = event_deque.front();
		event_deque.pop_front();
		json_output << "{" << std::endl;
		if (event.type == "build-start")
		{
			json_output << "\"type\" : " << "\"build-start\"," << std::endl;
			json_output << "\"name\" : " << "\"" << event.target_building << "\"," << std::endl;
			json_output << "\"producerID\" : \"" << event.producer_ID << "\"" << std::endl;
		}
		else if (event.type == "build-end")
		{

			json_output << "\"type\" : " << "\"build-end\"," << std::endl;
			json_output << "\"name\" : " << "\"" << event.target_building << "\"," << std::endl;
			json_output << "\"producerID\" : \"" << event.producer_ID << "\"," << std::endl;
			json_output << "\"producedIDs\": [ " << std::endl << "\"" << event.target_ID << "\"]" << std::endl;
		}
		else
		{
			json_output << "\"type\": " << "\"special\"," << std::endl;
			json_output << "\"name\" : " << "\"chronoboost\"," << std::endl;
			json_output << "\"triggeredBy\": \"" << event.producer_ID << "\"," << std::endl;
			json_output << "\"targetName\" : " << "\"" << event.target_building << "\"," << std::endl;
			json_output << "\"targetBuilding\": \"" << event.target_ID << "\"" << std::endl;
		}
		(event_deque.empty() == 1) ? json_output << "}" << std::endl << "]" << std::endl : json_output << "}," << std::endl;

	}
	(remaining_units > 0) ? json_output << "}," << std::endl : json_output << "}" << std::endl << "]" << std::endl << "}" << std::endl;
	json_output.close();
}

void JSON::print_worker_distribution(const int &time, const int& m_distribution, const int& g_distribution, const int& total_supply)
{

	json_output.open("Chronowith1.txt", std::ios::app);
	json_output << "{" << std::endl;
	json_output << "\"time\" : " << time << "," << std::endl;
	json_output << "\"status\" : " << "{" << std::endl;
	json_output << "\"workers\" : " << "{" << std::endl;
	json_output << "\"minerals\" : " << m_distribution << "," << std::endl;
	json_output << "\"vespene\" : " << g_distribution << std::endl << "}," << std::endl;
	json_output << "\"resources\" : " << "{" << std::endl;
	json_output << "\"minerals\" : " << Resources::minerals / 10 << "," << std::endl;
	json_output << "\"vespene\" : " << Resources::gas / 100 << "," << std::endl;
	json_output << "\"supply-used\" : " << total_supply - Resources::supply << "," << std::endl;
	json_output << "\"supply\" : " << total_supply << std::endl << "}" << std::endl << "}" << std::endl << "}," << std::endl;
	json_output.close();

}