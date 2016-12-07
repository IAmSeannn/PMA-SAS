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
	temp << spacer << "Meeting: " <<start_.getFormatted() << " - " << end_.getFormatted() << " Attendees: " << attendees_;
	return temp.str();
}
