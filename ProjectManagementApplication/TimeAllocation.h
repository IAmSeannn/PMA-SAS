#pragma once
#include <string>
#include "DateTime.h"
#include <tuple>

class TimeAllocation
{
public:
	virtual const std::string GetDetails() const = 0;
	void SetStart(std::string s) { start_ = s; }
	void SetEnd(std::string s) { end_ = s; }
	const int GetTimeSpent() const;
	friend bool operator<(const TimeAllocation & lhs, const TimeAllocation & rhs);

protected:
	DateTime start_;
	DateTime end_;
	std::string spacer = "   >";
};

std::ostream &operator<<(std::ostream &output, TimeAllocation *ta);