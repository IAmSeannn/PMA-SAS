#include "TimeAllocation.h"

std::string TimeAllocation::GetDetails()
{
	return "------this class shouldnt exist------";
}

int TimeAllocation::GetTimeSpent()
{
	return start_.GetDifferent(end_);
}