#pragma once
#include "TimeAllocation.h"

class Meeting : public TimeAllocation
{
public:
	Meeting();
	~Meeting();
	const std::string GetDetails() const;
	void GetInformationForNewClass();
	void SetAttendees(std::string s) { attendees_ = s; }
	std::string GetAttendees() { return attendees_; }
private:
	std::string attendees_;
};

