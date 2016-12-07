#pragma once
#include <string>
#include "DateTime.h"
#include "Task.h"
#include <vector>

class Project
{
private:
	std::string name_;
	std::string desc_;
	DateTime start_;
	DateTime deadline_;

	std::vector<Task> Tasks;

public:
	Project() {};
	Project(std::string name, std::string desc, std::string start, std::string deadline);
	
	std::string GetName() { return name_; };
	void SetName(std::string s) { name_ = s; }

	std::string GetDesc() { return desc_; }
	void SetDesc(std::string s) { desc_ = s; }

	std::vector<Task> GetTasks() { return Tasks; }
	void SetTasks(std::vector<Task> t) { Tasks = t; }

	void SetStart(std::string s) { start_ = s; }
	std::string GetStart() { return start_.getFormatted(); }

	void SetDeadline(std::string s) { deadline_ = s; }
	std::string GetDeadline() { return deadline_.getFormatted(); }

	int Project::GetMinutesSpent();
};

std::ostream &operator<<(std::ostream &output, Project p);

