#pragma once
#include "TimeAllocation.h"
class BugFix : public TimeAllocation
{
public:
	BugFix();
	~BugFix();
	const std::string GetDetails();
	void SetDesc(std::string s) { desc_ = s; }
	void SetID(int i) { id_ = i; }
private:
	std::string desc_;
	int id_;
};

