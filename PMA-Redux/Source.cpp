#include "DataCzar.h"
#include "MenuSystem.h"

int main(int argc, char* argv[])
{
	//todo: add checks incase path isnt valid
	//DataCzar Data(argv[1]);

	//DataCzar Data("testing.xml");
	//DataDisplayer::PrintTest(Data);

	//initialise static dataczar
	std::shared_ptr<DataCzar> d(new DataCzar);
	DataCzar::Current = d;

	MenuSystem::CommandLoadMainMenu();
}