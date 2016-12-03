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
		std::cout << p.GetName() << "\n\n";
	}

	std::cin.get();
	std::cin.get();
}