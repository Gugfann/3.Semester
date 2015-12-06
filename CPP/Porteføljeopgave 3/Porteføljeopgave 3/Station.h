#pragma once
#include <vector>
#include <string>
#include "Bil.h"

using namespace std;

class Station
{
public:
	Station();
	Station(string enAdresse);
	Bil *findBilStation(string etRegNr);
	void sletBilStation(Bil enBil);
	void addBil(Bil& enBil);
	vector<Bil> getBiler();
	~Station();
protected:
	string adresse;
	vector<Bil> biler;
};

