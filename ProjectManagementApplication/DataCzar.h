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

	static std::shared_ptr<DataCzar> Current;
	std::string path;

	tinyxml2::XMLError SetUp(const std::string & path);
	void SaveToFile();
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

