#pragma once
#include <string>
#include "DateTime.h"

class TimeAllocation
{
public:
	virtual std::string GetDetails();

protected:
	DateTime start_;
	DateTime end_;
};

