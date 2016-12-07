#include "Project.h"
#include "RuntimeMenu.h"

Project::Project(std::string name, std::string desc, std::string start, std::string deadline)
	: name_(name), desc_(desc), start_(start), deadline_(deadline)
{
}

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

int Project::GetMinutesSpent()
{
	int minutesSpent = 0;

	for (Task t : Tasks)
	{
		minutesSpent += t.GetMinutesSpent();
	}
	return minutesSpent;
}