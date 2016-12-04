#include "DataDisplayer.h"



DataDisplayer::DataDisplayer()
{
}


DataDisplayer::~DataDisplayer()
{
}

void DataDisplayer::PrintTest(DataCzar data)
{
	PrintPageLine();
	std::cout << "---Excellent Project Manager v1.0---\n";
	PrintPageLine();
	std::cout << "Number of projects loaded: " << data.GetProjects().size() << "\n";
	PrintPageLine();
	std::cout << "Currently Loaded Projects:\n";
	PrintSubLine();
	for (Project p : data.GetProjects())
	{
		std::cout << "	¬Project Name: " << p.GetName() << "\n";
		std::cout << "	¬Tasks Involved:\n";
		PrintSubLine();
		for (Task t : p.GetTasks())
		{

			std::cout << "		¬Task Name: " << t.GetName() << "\n";
			std::cout << "		¬Time Spent On Task:\n";
			PrintSubLine();
			for (TimeAllocation* pT : t.GetTAs())
			{
				std::cout << "			¬" << *pT << "\n";
			}
		}
		PrintPageLine();
	}
}

void DataDisplayer::PrintPageLine()
{
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void DataDisplayer::PrintSubLine()
{
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
}
