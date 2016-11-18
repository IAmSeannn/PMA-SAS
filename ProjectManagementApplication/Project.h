#pragma once
#include <string>
#include "DateTime.h"

class Project
{
private:
	std::string name_;
	std::string description_;
	DateTime start_;
	DateTime deadline_;

public:
	Project(std::string name, std::string desc, std::string start, std::string deadline);
};

