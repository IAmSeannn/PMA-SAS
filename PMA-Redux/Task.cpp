#include "Task.h"

Task::Task(){}

Task::~Task(){}

const int Task::GetMinutesSpent()
{
	int minutesSpent = 0;
	for (std::shared_ptr<TimeAllocation> ta : timeAllocations_)
	{
		minutesSpent += ta->GetTimeSpent();
	}

	return minutesSpent;
}

std::ostream &operator<<(std::ostream &output, Task & t)
{
	output << RuntimeMenu::TurnIntoSubtitle(t.name_, MagicStr::SpaceTask);
	output << MagicStr::SpaceTask << "Description: " << t.GetDesc() << "\n";
	output << RuntimeMenu::GetTimeSpentString(t.GetMinutesSpent(), MagicStr::SpaceTask);
	output << MagicStr::SpaceTask << "Started: " << t.start_.getFormatted() << "\n";
	output << MagicStr::SpaceTask << "Deadline: " << t.deadline_.getFormatted() << "\n";
	output << MagicStr::SpaceTask << "Time Allocations:\n";
	for (std::shared_ptr<TimeAllocation> pT : t.GetTAs())
	{
		output << pT << "\n";
	}
	return output;
}
