#pragma once
#include "TimeAllocation.h"

class Meeting : public TimeAllocation
{
public:
	Meeting();
	~Meeting();
	std::string GetDetails();
	void SetAttendees(std::string s) { attendees_ = s; }
private:
	std::string attendees_;
};

