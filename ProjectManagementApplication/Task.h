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
private:
	std::string name_;
	std::string description_;
	DateTime start_;
	DateTime deadline_;
	//std::vector<TimeAllocation> timeAllocations_;
};

