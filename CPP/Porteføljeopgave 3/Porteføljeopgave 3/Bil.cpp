#include "Bil.h"
#include "Kalender.h"



Bil::Bil()
{
}

Bil::Bil(string etRegNr):
	regNr(etRegNr)
{
	Kalender temp(19000101, 19000105);
	kalender.mergeKalender(temp);
}

string Bil::getRegNr()
{
	return regNr;
}

Kalender Bil::getKalender()
{
	return kalender;
}

bool Bil::isLedig()
{
	return ledig;
}

void Bil::kalenderUpdate(Kalender enKalender)
{
	ledig = true;
	for (int i = 0; i < enKalender.getDates().size(); i++)
	{
		if (!kalender.availability(enKalender.getDates()[i]))
		{			
			ledig = false;
			cout << "Bilen er reserveret i noget af den valgte periode" << endl;	
			break;
		}
	}

	if (ledig)
	{
		kalender.mergeKalender(enKalender);
	}

}

void Bil::transitUpdate()
{
	status = "Bilen er på eventyr";
}

void Bil::makeAvailable()
{
	status = "Bilen er til rådighed";
}

void Bil::makeUnavailable()
{
	status = "Bilen er ikke til rådighed";
}

void Bil::printStatus()
{
	cout << status << endl;
}


Bil::~Bil()
{
}
