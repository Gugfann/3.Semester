#pragma once
#include "Station.h"
#include "Kunde.h"
#include "Reservation.h"
class Reception
{
public:
	Reception();

	void makeReservation(string enMail, string etRegNr, int enStartDato, int enSlutDato);
	void hentBil(string enMail);
	void bilAfleveret(string etRegNr);

	Kunde createKunde(string navn, string adresse, int tlf, string mail);
	Reservation createReservation(Bil enBil, Kunde enKunde, int enStartDato, int enSlutDato);
	void addKunde(Kunde enKunde);
	void addReservation(Reservation enReservation);
	Kunde *findKunde(string enMail);
	Bil* findBil(string etRegNr);
	Reservation* findReservation(Kunde enKunde);

	~Reception();
protected:
	vector<Station> stationer;
	vector<Kunde> kunder;
	vector<Reservation> reservationer;
	int currentStation = 0;
};

