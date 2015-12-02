#pragma once
#include <string>
#include <iostream>
#include "Kalender.h"

using namespace std;

class Bil
{
public:
	Bil();
	Bil(string etRegNr);

	string getRegNr();
	Kalender getKalender();
	bool isLedig();
	void kalenderUpdate(Kalender enKalender);
	void transitUpdate();
	void makeAvailable();
	void makeUnavailable();
	void printStatus();
	~Bil();
protected:
	string regNr;
	string status;
	Kalender kalender;
	bool ledig;
};

