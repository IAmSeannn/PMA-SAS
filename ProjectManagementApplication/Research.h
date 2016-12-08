#pragma once
#include "TimeAllocation.h"

class Research : public TimeAllocation
{
public:
	Research();
	~Research();
	const std::string GetDetails() const;
	void SetDetails(std::string s) { details_ = s; }
private:
	std::string details_;
};

