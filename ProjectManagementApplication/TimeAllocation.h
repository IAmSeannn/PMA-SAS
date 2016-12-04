#pragma once
#include <string>
#include "DateTime.h"

class TimeAllocation
{
public:
	virtual const std::string GetDetails();
	void SetStart(std::string s) { start_ = s; }
	void SetEnd(std::string s) { end_ = s; }

	/*std::string operator<<(const TimeAllocation& ta)
	{
		return GetDetails();
	}*/

	/*std::ostream& operator<<(std::ostream& os)
	{
		return os << GetDetails();;
	}*/

	friend std::ostream &operator<<(std::ostream &output,
		const TimeAllocation &ta) {
		output << ta.GetDetails();
		return output;
	}

protected:
	DateTime start_;
	DateTime end_;
};

