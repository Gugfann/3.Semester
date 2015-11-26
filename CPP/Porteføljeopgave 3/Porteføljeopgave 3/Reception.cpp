#include "Reception.h"
#include <iostream>

using namespace std;

Reception::Reception()
{
}

void Reception::makeReservation(string enMail, string etRegNr, int enStartDato, int enSlutDato)
{
	Kunde* kundePtr = findKunde(enMail);
	Bil* bilPtr = findBil(etRegNr);

	if (kundePtr != nullptr && bilPtr != nullptr)
	{
		Reservation nyReservation = createReservation(*bilPtr, *kundePtr, enStartDato, enSlutDato);
		addReservation(nyReservation);
	}
	else
		cout << "You dun goofed!" << endl;
}

void Reception::hentBil(string enMail)
{
	Kunde* kundePtr = findKunde(enMail);
	Reservation* reservationsPtr = findReservation(*kundePtr);

	if (kundePtr != nullptr && reservationsPtr != nullptr)
	{

	}
	else
		cout << "You dun goofed!" << endl;
}

void Reception::bilAfleveret(string etRegNr)
{
	Bil* bilPtr = findBil(etRegNr);
	if (bilPtr != nullptr)
	{
		Reservation* reservationsPtr = findReservation();
	}
}

Kunde Reception::createKunde(string etNavn, string enAdresse, int etTlf, string enMail)
{
	Kunde(etNavn, enAdresse, etTlf, enMail);
}

Reservation Reception::createReservation(Bil enBil, Kunde enKunde, int enStartDato, int enSlutDato)
{
	Reservation(enBil, enKunde, enStartDato, enSlutDato);
}

void Reception::addKunde(Kunde enKunde)
{
	kunder.push_back(enKunde);
}

void Reception::addReservation(Reservation enReservation)
{
	reservationer.push_back(enReservation);
}

Kunde* Reception::findKunde(string enMail)
{
	for (int i = 0; i < kunder.size(); i++)
	{
		if (kunder[i].getMail() == enMail)
			return &kunder[i];		
	}

	return nullptr; //Kunde ikke fundet
}

Bil* Reception::findBil(string etRegNr)
{
	return stationer[currentStation].findBil(etRegNr);
}

Reservation* Reception::findReservation(Kunde enKunde)
{
	for (int i = 0; i < reservationer.size(); i++)
	{
		if (reservationer[i].getKunde().getMail() == enKunde.getMail())
			return &reservationer[i];
	}
	return nullptr;
}



Reception::~Reception()
{
}
