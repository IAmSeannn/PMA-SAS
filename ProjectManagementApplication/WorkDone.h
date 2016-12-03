#pragma once
#include "TimeAllocation.h"
class WorkDone : public TimeAllocation
{
public:
	WorkDone();
	~WorkDone();
	std::string GetDetails();
	void SetDesc(std::string s) { desc_ = s; }
private:
	std::string desc_;
};

