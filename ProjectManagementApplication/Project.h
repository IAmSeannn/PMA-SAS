#pragma once
#include <string>
#include "DateTime.h"
#include "Task.h"
#include <vector>

class Project
{
private:
	std::string name_;
	std::string description_;
	DateTime start_;
	DateTime deadline_;

	std::vector<Task> Tasks;

public:
	Project() {};
	Project(std::string name, std::string desc, std::string start, std::string deadline);
	std::string GetName() { return name_; };
	void SetName(std::string s) { name_ = s; }
	std::string GetDesc() { return description_; }
	void SetDesc(std::string s) { description_ = s; }
};

