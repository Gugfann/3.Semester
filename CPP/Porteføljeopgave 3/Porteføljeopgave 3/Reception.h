#pragma once
#include "Station.h"
#include "Kunde.h"
#include "Reservation.h"
class Reception
{
public:
	Reception();

	void opretKunde(string navn, string adresse, int tlf, string mail);
	void makeReservation(string enMail, string etRegNr, int enStartDato, int enSlutDato);
	void hentBil(string enMail);
	void bilAfleveret(string etRegNr);
	void flytBil(string etRegNr);
	void modtagBil(string etRegNr);

	void addBil(Bil& enBil);
	void addStation(Station& enStation);

	Reservation* findGammelReservation(Kunde enKunde);
	Reservation* findReservation(Kunde enKunde);
	Reservation* findReservation(Bil enBil);
	vector<Bil> getInventory();
	vector<Station> getStationer();

	~Reception();

protected:
	Kunde createKunde(string navn, string adresse, int tlf, string mail);
	Reservation createReservation(Bil* enBil, Kunde* enKunde, int enStartDato, int enSlutDato);
	void addBilStation(Bil& enBil);
	void addKunde(Kunde& enKunde);
	void addReservation(Reservation& enReservation);
	void sletReservation(Reservation& enReservation);
	Kunde *findKunde(string enMail);
	Bil* findBilStation(string etRegNr);
	Bil* findBilFirma(string etRegNr);
	void sletBilFirma(Bil enBil);


	vector<Station> stationer;
	vector<Kunde> kunder;
	vector<Reservation> reservationer; 
	vector<Reservation> gamleReservationer;
	vector<Bil> inventory;
	int currentStation = 0;
};

