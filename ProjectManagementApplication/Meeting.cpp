#include "Meeting.h"

Meeting::Meeting()
{
}


Meeting::~Meeting()
{
}

std::string Meeting::GetDetails()
{
	std::stringstream temp;
	temp << " " << attendees_;
	//temp << start_.getFormatted() << " " << end_.getFormatted() << " " << attendees_;
	return temp.str();
}
