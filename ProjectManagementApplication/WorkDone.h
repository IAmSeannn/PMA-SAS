#pragma once
#include "TimeAllocation.h"
class WorkDone : public TimeAllocation
{
public:
	WorkDone();
	~WorkDone();
	std::string GetDetails();
private:
	std::string desc_;
};

