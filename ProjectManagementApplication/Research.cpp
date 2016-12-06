#include "Research.h"



Research::Research()
{
}


Research::~Research()
{
}

const std::string Research::GetDetails()
{
	std::stringstream temp;
	temp << "   >Started: " << start_.getFormatted() << " Ended: " << end_.getFormatted() << " What Was Researched: " << details_;
	return temp.str();
}