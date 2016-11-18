#include <iostream>
#include <sstream>
#include <fstream>
#include "parser.h"

void TryLoadFile(std::string path, std::stringstream &buf)
{
	std::ifstream file(path);

	if (file)
	{
		buf << file.rdbuf();
		file.close();
	}
	else
	{
		std::cout << "Error loading file!";
	}
}

int main(int argc, char* argv[])
{
	std::stringstream buffer;

	if (argv[1] != NULL)
	{
		TryLoadFile(argv[1], buffer);
	}
	else
	{
		std::cout << "No command line specified, reverting to plan b \n";
		TryLoadFile("../ProjectManagementApplication/testing.pma", buffer);
	}

	Parser p(buffer);




	std::cin.get();
	std::cin.get();
}