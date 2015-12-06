#include "Station.h"



Station::Station()
{
}

Station::Station(string enAdresse):
	adresse(enAdresse)
{
}

Bil* Station::findBilStation(string etRegNr)
{
	for (int i = 0; i < biler.size(); i++)
	{
		if (biler[i].getRegNr() == etRegNr)
			return &biler[i];
	}
	return nullptr;
}

void Station::sletBilStation(Bil enBil)
{
	for (int i = 0; i < biler.size(); i++)
	{
		if (enBil.getRegNr() == biler[i].getRegNr())
		{
			biler.erase(biler.begin() + i);
			break;
		}
	}
}

void Station::addBil(Bil& enBil)
{
	biler.push_back(enBil);
}

vector<Bil> Station::getBiler()
{
	return biler;
}

Station::~Station()
{
}
