#include "DataDisplayer.h"



DataDisplayer::DataDisplayer()
{
}


DataDisplayer::~DataDisplayer()
{
}

void DataDisplayer::PrintTest(DataCzar data)
{
	std::cout << "------------------------------------\n";
	std::cout << "---Excellent Project Manager v1.0---\n";
	std::cout << "------------------------------------\n";
	std::cout << "Number of projects loaded: " << data.GetProjects().size() << "\n";
	std::cout << "Currently Loaded Projects:\n";
	for (Project p : data.GetProjects())
	{
		std::cout << p;
	}
}
