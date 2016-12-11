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

void TimeAllocation::PopulatePersonIDs(std::string s)
{
	std::istringstream iss(s);

	int i;

	while (iss >> i)
	{
		PersonIDs.push_back(i);

		if (iss.peek() == ',' || iss.peek() == ' ')
		{
			iss.ignore();
		}
	}
}

void TimeAllocation::SetupNewStartTime()
{
	std::cout << "When was the work started? dd/mm/yyyy hh:mm\n";
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	DateTime temp(input);
	start_ = temp;
}

void TimeAllocation::SetupNewEndTime()
{
	std::cout << "When was the work ended? dd/mm/yyyy hh:mm\n";
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	DateTime temp(input);
	end_ = temp;
}

void TimeAllocation::SetupNewPersonsInvolved()
{
	std::string temp;
	std::cout << "Please enter the ID of any Persons assigned to this, separated by commas (no spaces):\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, temp);
	PopulatePersonIDs(temp);
}