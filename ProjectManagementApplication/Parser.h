#pragma once
#include <sstream>
#include <list>
#include "Project.h"

class Parser
{
public:
	Parser(const std::stringstream &);
	std::list<Project> Projects;
};

