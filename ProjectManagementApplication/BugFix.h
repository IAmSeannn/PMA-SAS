#pragma once
#include "TimeAllocation.h"
class BugFix : public TimeAllocation
{
public:
	BugFix();
	~BugFix();
	std::string GetDetails();
private:
	std::string desc_;
	int id_;
};

