#pragma once
#include "TimeAllocation.h"

class Meeting : public TimeAllocation
{
public:
	Meeting();
	~Meeting();
	std::string GetDetails();
private:
	std::string attendees_;
};

