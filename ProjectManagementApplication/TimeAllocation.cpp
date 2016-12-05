#include "TimeAllocation.h"

const std::string TimeAllocation::GetDetails()
{
	return "------this class shouldnt exist------";
}

int TimeAllocation::GetTimeSpent()
{
	return start_.GetDifferent(end_);
}

std::ostream &operator<<(std::ostream &output, TimeAllocation *ta)
{
	output << ta->GetDetails();
	return output;
}