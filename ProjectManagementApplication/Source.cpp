#include <iostream>
#include "XMLTutorial.h"

int main(int argc, char* argv[])
{

	XMLTutorial tut;
	//tut.RunCreate();  //runs code that creates an xml file
	tut.RunLoad();		//runs code that loads an xml file

	std::cin.get();
	std::cin.get();
}