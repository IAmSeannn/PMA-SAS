#include "DataCzar.h"



DataCzar::DataCzar(std::string path)
{
	//take path and load xml file
	//decode xml and populate this class
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("testing.xml");
}


DataCzar::~DataCzar()
{
}
