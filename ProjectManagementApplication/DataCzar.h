#pragma once
#include <string>
#include <vector>
#include "Project.h"
#include "tinyxml2.h"

class DataCzar
{
public:
	DataCzar(std::string);
	~DataCzar();
	std::vector<Project> GetProjects() {
		return Projects;
	};
private:
	std::vector<Project> Projects;
};

