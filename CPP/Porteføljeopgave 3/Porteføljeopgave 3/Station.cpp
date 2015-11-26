#include "Station.h"



Station::Station()
{
}

Bil* Station::findBil(string etRegNr)
{
	for (int i = 0; i < biler.size(); i++)
	{
		if (biler[i].getRegNr() == etRegNr)
			return &biler[i];
	}
	return nullptr;
}

Station::~Station()
{
}
