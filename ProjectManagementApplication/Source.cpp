#include <iostream>
#include "DataCzar.h"



int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);
	DataCzar Data("testing.xml");

	std::cout << "Number of projects is :: " << Data.GetProjects().size() << "\n";

	std::cout << "Here is a list of prohects, by name :: \n\n\n";

	for (Project p : Data.GetProjects())
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

	std::cin.get();
	std::cin.get();
}