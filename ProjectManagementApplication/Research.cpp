#include "Research.h"



Research::Research()
{
}


Research::~Research()
{
}

const std::string Research::GetDetails() const
{
	std::stringstream temp;
	temp << spacer << "Research: " << start_.getFormatted() << " - " << end_.getFormatted() << " Topic: " << details_;
	return temp.str();
}