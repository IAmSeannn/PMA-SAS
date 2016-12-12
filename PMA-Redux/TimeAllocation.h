#pragma once
#include <string>
#include "DateTime.h"
#include <tuple>
#include <iostream>
#include <memory>
#include <vector>
#include "MagicStr.h"

class TimeAllocation
{
public:
	virtual const std::string GetDetails() const = 0;
	virtual void SetUpNewClassFromUser() = 0;
	virtual void EditClassFromUser() = 0;
	void SetStart(std::string s) { start_ = s; }
	std::string GetStart() { return start_.getFormatted(); }
	std::string GetEnd() { return end_.getFormatted(); }
	void SetEnd(std::string s) { end_ = s; }
	const int GetTimeSpent() const;
	std::vector<int> & GetPersonIDs() { return PersonIDs; }
	void SetPersonIDs(std::vector<int> & v) { PersonIDs = v; }
	friend bool operator<(std::shared_ptr<TimeAllocation> lhs, std::shared_ptr<TimeAllocation> rhs);

protected:
	DateTime start_;
	DateTime end_;
	std::vector<int> PersonIDs;
	const std::string GetPersonNamesFormatted() const;
	void PopulatePersonIDs(std::string);
	void SetupNewStartTime();
	void SetupNewEndTime();
	void TimeAllocation::SetupNewPersonsInvolved();
};

std::ostream &operator<<(std::ostream &output, std::shared_ptr<TimeAllocation> ta);