#pragma once
#include "DataCzar.h"
#include <iostream>

class DataDisplayer
{
public:
	DataDisplayer();
	~DataDisplayer();
	static void PrintTest(DataCzar data);

private:
	static void PrintPageLine();
	static void PrintSubLine();
};

