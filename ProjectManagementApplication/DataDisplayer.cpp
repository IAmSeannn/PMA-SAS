#include "DataDisplayer.h"



DataDisplayer::DataDisplayer()
{
}


DataDisplayer::~DataDisplayer()
{
}

void DataDisplayer::PrintTest()
{
	std::cout << "------------------------------------\n";
	std::cout << "---Excellent Project Manager v1.0---\n";
	std::cout << "------------------------------------\n";
	std::cout << "Number of projects loaded: " << DataCzar::Current->GetProjects().size() << "\n";
	std::cout << "Currently Loaded Projects:\n";
	for (Project p : DataCzar::Current->GetProjects())
	{
		std::cout << p;
	}
}
