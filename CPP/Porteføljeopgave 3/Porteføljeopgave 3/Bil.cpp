#include "Bil.h"
#include "Kalender.h"



Bil::Bil()
{
}

string Bil::getRegNr()
{
	return regNr;
}

void Bil::kalenderUpdate(Kalender enKalender)
{
}

void Bil::transitUpdate()
{
	status = "Bilen er p� eventyr";
}

void Bil::makeAvailable()
{
	status = "Bilen er til r�dighed";
}

void Bil::makeUnavailable()
{
	status = "Bilen er ikke til r�dighed";
}

void Bil::printStatus()
{
	cout << status << endl;
}


Bil::~Bil()
{
}
