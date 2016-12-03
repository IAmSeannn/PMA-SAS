#include "DataCzar.h"

DataCzar::DataCzar(std::string path)
{
	LoadInXML(path);
}

void DataCzar::LoadInXML(std::string path)
{
	//load in file and get pointer to root
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("testing.xml");
	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();

	//load projects using root
	LoadInProjects(pRoot);
}

void DataCzar::LoadInProjects(tinyxml2::XMLNode * pRoot)
{
	//loop through all projects
	tinyxml2::XMLElement * pProjectHeader = pRoot->FirstChildElement("project");
	while (pProjectHeader != nullptr)
	{
		Project p;

		//get element of name
		tinyxml2::XMLElement * pProjectElement = pProjectHeader->FirstChildElement("name");
		p.SetName(pProjectElement->GetText());
		//do same again for desc
		pProjectElement = pProjectHeader->FirstChildElement("desc");
		p.SetDesc(pProjectElement->GetText());


		//do same for tasks
		p.SetTasks(LoadInTasks(pProjectHeader));



		//add project to list of projects
		Projects.push_back(p);
		//move xml pointer to next project in file
		pProjectHeader = pProjectHeader->NextSiblingElement("project");
	}
}

std::vector<Task> DataCzar::LoadInTasks(tinyxml2::XMLNode * pCurrentProject)
{
	//temp vector to store tasks as added
	std::vector<Task> temp;
	//loop through all tasks
	tinyxml2::XMLElement * pTaskHeader = pCurrentProject->FirstChildElement("task");
	while (pTaskHeader != nullptr)
	{
		Task t;

		//get element of name
		tinyxml2::XMLElement * pTaskElement = pTaskHeader->FirstChildElement("name");
		t.SetName(pTaskElement->GetText());
		//do same again for desc
		pTaskElement = pTaskHeader->FirstChildElement("desc");
		t.SetDesc(pTaskElement->GetText());

		//add t to temp vector
		temp.push_back(t);

		//move xml pointer to next project in file
		pTaskHeader = pTaskHeader->NextSiblingElement("task");
	}
	return temp;
}


DataCzar::~DataCzar()
{
}


