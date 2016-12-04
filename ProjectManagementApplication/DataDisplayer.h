#pragma once
#include "DataCzar.h"
#include <iostream>

class DataDisplayer
{
public:
	DataDisplayer();
	~DataDisplayer();
	static void PrintTest(DataCzar data)
	{
		std::cout << "Number of projects is :: " << data.GetProjects().size() << "\n";

		std::cout << "Here is a list of prohects, by name :: \n\n\n";

		for (Project p : data.GetProjects())
		{
			std::cout << p.GetName() << "\n";
			std::cout << "Tasks Involved:: \n";

			for (Task t : p.GetTasks())
			{
				std::cout << t.GetName() << "\n";

				for (TimeAllocation* pT : t.GetTAs())
				{
					std::cout << "          -" << pT->GetDetails() << "\n";
				}
			}

			std::cout << "\n";
		}
	}
};

