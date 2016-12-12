#pragma once
#include <string>
#include <vector>
#include "Project.h"
#include "tinyxml2.h"
#include "Person.h"

class DataCzar
{
public:
	DataCzar();
	~DataCzar();

	static std::shared_ptr<DataCzar> Current; //static currrently loaded project.
	std::string path; //path of loaded project

	tinyxml2::XMLError SetUp(const std::string & path); //loads in xml and sets up all the dataczars members. Returns an XMLError to let us know if it was successful.
	void SaveToFile(); //saves the current dataczar data to an xml file at path (the member), overwriting anything existing.
	std::vector<Project> & GetProjects() { return Projects; };
	std::vector<Person> & GetPersons(){ return Persons; };
private:
	std::vector<Project> Projects;
	std::vector<Person> Persons;
	tinyxml2::XMLError LoadInXML(const std::string);
	void LoadInProjects(tinyxml2::XMLNode *);
	void LoadInPersons(tinyxml2::XMLNode *);
	std::vector<Task> LoadInTasks(tinyxml2::XMLNode *);
	std::vector<std::shared_ptr<TimeAllocation>> LoadInTAs(tinyxml2::XMLNode *);
	std::vector<int> LoadInPersonIDs(tinyxml2::XMLNode * pPersonRoot);
};

