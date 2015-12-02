#include "Reservation.h"



Reservation::Reservation()
{
}

Reservation::Reservation(Bil enBil, Kunde enKunde, int enStartDato, int enSlutDato):
	bil(enBil), kunde(enKunde)
{
	kalender = createKalender(enStartDato, enSlutDato);
	bil.kalenderUpdate(kalender);
}

Kunde Reservation::getKunde()
{
	return kunde;
}

Kalender Reservation::getKalender()
{
	return kalender;
}

Bil Reservation::getBil()
{
	return bil;
}

void Reservation::bilAfhentet()
{
	bil.makeUnavailable();
}


Kalender Reservation::createKalender(int enStartDato, int enSlutDato)
{
	return Kalender(enStartDato, enSlutDato);
}

Reservation::~Reservation()
{
}
