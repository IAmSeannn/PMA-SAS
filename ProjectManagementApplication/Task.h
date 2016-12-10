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
#include <memory>

class Task
{
public:
	Task();
	~Task();
	std::string & GetName() { return name_; }
	void SetName(std::string s) { name_ = s; }
	void SetDesc(std::string s) { desc_ = s; }
	std::string GetDesc() { return desc_; }
	void SetTAs(std::vector<std::shared_ptr<TimeAllocation>> & ta) { timeAllocations_ = ta; }
	std::vector<std::shared_ptr<TimeAllocation>> & GetTAs() { return timeAllocations_; }
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
	std::vector<std::shared_ptr<TimeAllocation>> timeAllocations_;
};



