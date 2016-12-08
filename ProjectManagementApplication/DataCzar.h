#pragma once
#include <string>
#include <vector>
#include "Project.h"
#include "tinyxml2.h"

class DataCzar
{
public:
	DataCzar();
	~DataCzar();

	static DataCzar * Current;
	std::string path;

	tinyxml2::XMLError SetUp(const std::string & path);
	void SaveToFile();
	std::vector<Project> & GetProjects() {
		return Projects;
	};
private:
	std::vector<Project> Projects;
	tinyxml2::XMLError LoadInXML(const std::string);
	void LoadInProjects(tinyxml2::XMLNode *);
	std::vector<Task> LoadInTasks(tinyxml2::XMLNode *);
	std::vector<TimeAllocation*> LoadInTAs(tinyxml2::XMLNode *);
};

