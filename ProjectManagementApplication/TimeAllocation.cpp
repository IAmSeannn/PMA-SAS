#include "TimeAllocation.h"

const int TimeAllocation::GetTimeSpent() const
{
	return start_.GetDifferent(end_);
}

std::ostream &operator<<(std::ostream &output, std::shared_ptr<TimeAllocation> ta)
{
	output << ta->GetDetails();
	return output;
}

bool operator<(const TimeAllocation & lhs, const TimeAllocation & rhs)
{
	if (rhs.start_.GetTimeInMinutes() != lhs.start_.GetTimeInMinutes())
	{
		return rhs.start_.GetTimeInMinutes() < lhs.start_.GetTimeInMinutes();
	}
	else
	{
		return rhs.end_.GetTimeInMinutes() < lhs.end_.GetTimeInMinutes();
	}
}