#pragma once
#include "TimeAllocation.h"
class WorkDone : public TimeAllocation
{
public:
	WorkDone();
	~WorkDone();
	const std::string GetDetails() const;
	void GetInformationForNewClass();
	void SetDesc(std::string s) { desc_ = s; }
	std::string GetDesc() { return desc_; }
private:
	std::string desc_;
};

