#pragma once
#include <string>

using namespace std;

class Bil
{
public:
	Bil();
	string getRegNr();
	void kalenderUpdate(Kalender enKalender);
	void makeAvailable();
	void makeUnavailable();
	~Bil();
protected:
	string regNr;
	string status;
};

