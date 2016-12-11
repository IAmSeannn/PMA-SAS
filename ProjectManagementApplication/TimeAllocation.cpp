#include "TimeAllocation.h"
#include "DataCzar.h"
#include <algorithm>

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

const std::string TimeAllocation::GetPersonNamesFormatted() const
{
	std::stringstream temp;

	for (auto i : PersonIDs)
	{
		for (auto p : DataCzar::Current->GetPersons())
		{
			if (i == p.GetID())
			{
				temp << p.GetName() << ". ";
			}
		}
	}
	return temp.str();
}