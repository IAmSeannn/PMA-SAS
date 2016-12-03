#include "DataCzar.h"



DataCzar::DataCzar(std::string path)
{
	//take path and load xml file
	//decode xml and populate this class
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("testing.xml");
	//for each project, add to projects vector
	//fill each project with tasks
	//fill each task with TAs
	//complete

	//get pointer to the root

	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();

	//loop through all projects
	tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("project");
	while (pElement != nullptr)
	{
		//get contents of project and put it somewhere useful
		//temp storage for any strings gotten
		std::string tempName;
		std::string tempDesc;

		//get element of name
		tinyxml2::XMLElement * pProjectElement = pElement->FirstChildElement("name");
		tempName = pProjectElement->GetText();
		//do same again for desc
		pProjectElement = pElement->FirstChildElement("desc");
		tempDesc = pProjectElement->GetText();

		//finally, create new project, add to vector
		//currently has blank datetimes
		Project p(tempName, tempDesc, " ", " ");
		Projects.push_back(p);

		//move xml pointer to next project in file
		pElement = pElement->NextSiblingElement("project");
	}

}


DataCzar::~DataCzar()
{
}
