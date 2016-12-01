#pragma once
#include <string>
#include "DateTime.h"

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
};

