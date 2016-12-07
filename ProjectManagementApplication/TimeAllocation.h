#pragma once
#include <string>
#include "DateTime.h"
#include <tuple>

class TimeAllocation
{
public:
	virtual const std::string GetDetails();
	void SetStart(std::string s) { start_ = s; }
	void SetEnd(std::string s) { end_ = s; }
	int GetTimeSpent();
	friend bool operator<(TimeAllocation & lhs, TimeAllocation & rhs);

protected:
	DateTime start_;
	DateTime end_;
	std::string spacer = "   >";
};

std::ostream &operator<<(std::ostream &output, TimeAllocation *ta);