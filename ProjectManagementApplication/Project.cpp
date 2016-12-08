#include "Project.h"
#include "RuntimeMenu.h"

std::ostream &operator<<(std::ostream &output, Project p)
{
	std::string space = "";
	output << RuntimeMenu::TurnIntoSubtitle(p.GetName(), space);
	output << RuntimeMenu::GetTimeSpentString(p.GetMinutesSpent(), space);
	output << space << "Started: " << p.GetStart() << "\n";
	output << space << "Deadline: " << p.GetDeadline() << "\n";
	output << "------\n";
	output << "Tasks:\n";
	output << "------\n";

	for (Task t : p.GetTasks())
	{
		output << t;
	}

	return output;
}

const int Project::GetMinutesSpent()
{
	int minutesSpent = 0;

	for (Task t : Tasks)
	{
		minutesSpent += t.GetMinutesSpent();
	}
	return minutesSpent;
}