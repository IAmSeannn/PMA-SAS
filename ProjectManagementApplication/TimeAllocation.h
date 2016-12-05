#pragma once
#include <string>
#include "DateTime.h"

class TimeAllocation
{
public:
	virtual const std::string GetDetails();
	void SetStart(std::string s) { start_ = s; }
	void SetEnd(std::string s) { end_ = s; }
	int GetTimeSpent();

protected:
	DateTime start_;
	DateTime end_;
};

std::ostream &operator<<(std::ostream &output, TimeAllocation *ta);

