#pragma once
#include "TimeAllocation.h"
class BugFix : public TimeAllocation
{
public:
	BugFix();
	~BugFix();
	const std::string GetDetails() const;
	void GetInformationForNewClass();
	void SetDesc(std::string s) { desc_ = s; }
	std::string GetDesc() { return desc_; }
	void SetID(int i) { id_ = i; }
	int GetID() { return id_; }
private:
	std::string desc_;
	int id_;
};

