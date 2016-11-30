#include <iostream>
#include "tinyxml2.h"

int main(int argc, char* argv[])
{

	tinyxml2::XMLDocument doc;
	doc.LoadFile("../ProjectManagementApplication/testing.xml");

	const char* title = doc.FirstChildElement("note")->FirstChildElement("body")->GetText();
	printf("Name of play (1): %s\n", title);

	tinyxml2::XMLText* textNode = doc.FirstChildElement("note")->FirstChildElement("to")->FirstChild()->ToText();
	title = textNode->Value();
	printf("addressed to (2): %s\n", title);

	std::cin.get();
	std::cin.get();
}