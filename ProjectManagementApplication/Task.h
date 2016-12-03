#pragma once
#include <string>
#include <vector>
#include "DateTime.h"
#include "TimeAllocation.h"

class Task
{
public:
	Task();
	~Task();
	std::string GetName() { return name_; }
	void SetName(std::string s) { name_ = s; }
	void SetDesc(std::string s) { desc_ = s; }
private:
	std::string name_;
	std::string desc_;
	DateTime start_;
	DateTime deadline_;
	//std::vector<TimeAllocation> timeAllocations_;
};

