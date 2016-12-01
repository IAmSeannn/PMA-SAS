#include <iostream>
#include "tinyxml2.h"

int main(int argc, char* argv[])
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("../ProjectManagementApplication/testing.xml");

	tinyxml2::XMLText* textNode = doc.FirstChildElement("project")->FirstChildElement("task")->FirstChildElement("name")->FirstChild()->ToText();
	auto name = textNode->Value();

	std::cout << "The name of the first task is :: " << name;

	std::cin.get();
	std::cin.get();
}