#pragma once
#include <string>
#include "DateTime.h"

class TimeAllocation
{
public:
	TimeAllocation();
	~TimeAllocation();

	virtual std::string GetDetails() = 0;

protected:
	DateTime start_;
	DateTime end_;
};

