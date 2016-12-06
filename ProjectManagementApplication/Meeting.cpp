#include "Meeting.h"

Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}

const std::string Meeting::GetDetails()
{
	std::stringstream temp;
	temp << "   >Started: " <<start_.getFormatted() << " Ended: " << end_.getFormatted() << " Attendees: " << attendees_;
	return temp.str();
}
