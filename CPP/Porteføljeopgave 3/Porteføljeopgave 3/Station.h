#pragma once
#include <vector>
#include <string>
#include "Bil.h"

using namespace std;

class Station
{
public:
	Station();
	Bil *findBil(string etRegNr);
	~Station();
protected:
	string adresse;
	vector<Bil> biler;
};

