#include <iostream>
#include "DataCzar.h"
#include "DataDisplayer.h"


int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);
	DataCzar Data("testing.xml");
	DataDisplayer::PrintTest(Data);
	

	std::cin.get();
	std::cin.get();
}