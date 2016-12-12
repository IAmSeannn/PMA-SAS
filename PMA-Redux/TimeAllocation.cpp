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

bool operator<(std::shared_ptr<TimeAllocation> lhs, std::shared_ptr<TimeAllocation> rhs)
{
	if (rhs->start_.GetTimeInMinutes() != lhs->start_.GetTimeInMinutes())
	{
		return rhs->start_.GetTimeInMinutes() < lhs->start_.GetTimeInMinutes();
	}
	else
	{
		return rhs->end_.GetTimeInMinutes() < lhs->end_.GetTimeInMinutes();
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
	//ERROR LOCATION, UNSURE WHY
	std::cout << "When was the work started? dd/mm/yyyy hh:mm\n";
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, input);
	DateTime temp(input);
	start_ = temp;
}

void TimeAllocation::SetupNewEndTime()
{
	//ERROR LOCATION, UNSURE WHY
	std::cout << "When was the work ended? dd/mm/yyyy hh:mm\n";
	std::string input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, input);
	DateTime temp(input);
	end_ = temp;
}

void TimeAllocation::SetupNewPersonsInvolved()
{
	//ERROR LOCATION, UNSURE WHY
	std::string temp;
	std::cout << "Please enter the ID of any Persons assigned to this, separated by commas (no spaces):\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin >> std::ws, temp);
	PopulatePersonIDs(temp);
}