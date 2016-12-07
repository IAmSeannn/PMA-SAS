#include "Task.h"



Task::Task()
{
}


Task::~Task()
{
}

int Task::GetMinutesSpent()
{
	int minutesSpent = 0;
	for (TimeAllocation* ta : timeAllocations_)
	{
		minutesSpent += ta->GetTimeSpent();
	}

	return minutesSpent;
}

std::ostream &operator<<(std::ostream &output, Task t)
{
	std::string space = "  ";
	output << RuntimeMenu::TurnIntoSubtitle(t.GetName(), space);
	output << RuntimeMenu::GetTimeSpentString(t.GetMinutesSpent(), space);
	output << space << "Started: " << t.GetStart() << "\n";
	output << space << "Deadline: " << t.GetDeadline() << "\n";
	output << space << "Time Allocations:\n";
	for (TimeAllocation* pT : t.GetTAs())
	{
		output << pT << "\n";
	}
	return output;
}
