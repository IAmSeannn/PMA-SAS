#pragma once
#include "TimeAllocation.h"
class Research : public TimeAllocation
{
public:
	Research();
	~Research();
	const std::string GetDetails() const;
	void SetUpNewClassFromUser();
	void SetDetails(std::string s) { details_ = s; }
	std::string GetDetails() { return details_; }
private:
	std::string details_;
};

