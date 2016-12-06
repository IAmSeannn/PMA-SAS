#include "Task.h"



Task::Task()
{
}


Task::~Task()
{
}

std::string Task::GetTimeSpent()
{
	int minutesSpent = 0;
	for (TimeAllocation* ta : timeAllocations_)
	{
		minutesSpent += ta->GetTimeSpent();
	}

	int minute, hour, day, month, year;

	year = minutesSpent / 518400;
	minutesSpent = minutesSpent % 518400;
	month = minutesSpent / 43200;
	minutesSpent = minutesSpent % 43200;
	day = minutesSpent / 1440;
	minutesSpent = minutesSpent % 1440;
	hour = minutesSpent / 60;
	minutesSpent = minutesSpent % 60;
	minute = minutesSpent;

	std::stringstream temp;
	temp << "Time Worked On Task: Years: " << year << " Months: " << month << " Days: " << day << " Hours: " << hour << " Minutes: " << minute;
	return temp.str();
}

std::ostream &operator<<(std::ostream &output, Task t)
{
	output << "  >Task Name: " << t.GetName() << "\n";
	output << "  >" << t.GetTimeSpent() << "\n";
	output << "  >Time Allocations:\n";
	for (TimeAllocation* pT : t.GetTAs())
	{
		output << pT << "\n";
	}
	return output;
}
