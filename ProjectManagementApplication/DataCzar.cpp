#include "DataCzar.h"



DataCzar::DataCzar(std::string path)
{
	//take path and load xml file
	//decode xml and populate this class
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("testing.xml");
	//for each project, add to projects vector
	//fill each project with tasks
	//fill each task with TAs
	//complete
}


DataCzar::~DataCzar()
{
}
