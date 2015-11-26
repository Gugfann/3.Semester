#pragma once
#include <string>
#include <iostream>

using namespace std;

class Bil
{
public:
	Bil();
	string getRegNr();
	void kalenderUpdate(Kalender enKalender);
	void transitUpdate();
	void makeAvailable();
	void makeUnavailable();
	void printStatus();
	~Bil();
protected:
	string regNr;
	string status;
};

