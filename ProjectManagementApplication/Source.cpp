#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argv[1] != NULL)
	{
		std::cout << "Arg is :: " << argv[1] << "\n";

		std::ifstream file(argv[1]);

		if (file)
		{
			std::stringstream buffer;

			buffer << file.rdbuf();

			file.close();

			// operations on the buffer...

			std::cout << "VICTORY" << "\n\n";

			std::cout << buffer.str();
		}
		else
		{
			std::cout << "Error loading file!";
		}
	}
	else
	{
		std::cout << "No command line specified!";
	}
}