#include "Project.h"
#include "RuntimeMenu.h"

const static std::string SpaceProject;
const static std::string SpaceTask;
const static std::string SpaceTA;

std::ostream &operator<<(std::ostream &output, Project p)
{
	output << RuntimeMenu::TurnIntoSubtitle(p.GetName(), MagicStr::SpaceProject);
	output << RuntimeMenu::GetTimeSpentString(p.GetMinutesSpent(), MagicStr::SpaceProject);
	output << MagicStr::SpaceProject << "Started: " << p.GetStart() << "\n";
	output << MagicStr::SpaceProject << "Deadline: " << p.GetDeadline() << "\n";
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