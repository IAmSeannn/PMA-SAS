#pragma once
#include <string>
#include <vector>
#include "DateTime.h"
#include "TimeAllocation.h"
#include "Meeting.h"
#include "BugFix.h"
#include "WorkDone.h"
#include "Research.h"
#include <iostream>
#include "RuntimeMenu.h"

class Task
{
public:
	Task();
	~Task();
	std::string & GetName() { return name_; }
	void SetName(std::string s) { name_ = s; }
	void SetDesc(std::string s) { desc_ = s; }
	void SetTAs(std::vector<TimeAllocation*> & ta) { timeAllocations_ = ta; }
	std::vector<TimeAllocation*> & GetTAs() { return timeAllocations_; }
	void SetStart(std::string s) { start_ = s; }
	std::string GetStart() { return start_.getFormatted(); }
	void SetDeadline(std::string s) { deadline_ = s; }
	std::string GetDeadline() { return deadline_.getFormatted(); }

	friend std::ostream &operator<<(std::ostream &output, Task & t);

	const int Task::GetMinutesSpent();
	
private:
	std::string name_;
	std::string desc_;
	DateTime start_;
	DateTime deadline_;
	std::vector<TimeAllocation*> timeAllocations_;
};



