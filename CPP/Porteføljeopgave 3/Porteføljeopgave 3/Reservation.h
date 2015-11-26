#pragma once
#include "Kalender.h"
#include "Bil.h"
#include "Kunde.h"

class Reservation
{
public:
	Reservation();
	Reservation(Bil enBil, Kunde enKunde, int enStartDato, int enSlutDato);

	Kunde getKunde();
	Kalender getKalender();
	Bil getBil();

	void bilAfhentet();

	Kalender createKalender(int enStartDato, int enSlutDato);
	~Reservation();
protected:
	Bil bil;
	Kunde kunde;
	Kalender kalender;
};

