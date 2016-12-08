#pragma once
#include "TimeAllocation.h"
class WorkDone : public TimeAllocation
{
public:
	WorkDone();
	~WorkDone();
	const std::string GetDetails() const;
	void SetDesc(std::string s) { desc_ = s; }
private:
	std::string desc_;
};

