#include "Reception.h"
#include <iostream>

using namespace std;

Reception::Reception()
{
}

void Reception::opretKunde(string navn, string adresse, int tlf, string mail)
{
	kunder.push_back(createKunde(navn, adresse, tlf, mail));
}

void Reception::makeReservation(string enMail, string etRegNr, int enStartDato, int enSlutDato)
{
	Kunde* kundePtr = findKunde(enMail);
	Bil* bilPtr = findBilStation(etRegNr);

	if (kundePtr != nullptr && bilPtr != nullptr)
	{
		Reservation nyReservation = createReservation(*bilPtr, *kundePtr, enStartDato, enSlutDato);
		if (nyReservation.getKalender().isValid() && nyReservation.getBil().isLedig())
			addReservation(nyReservation);
		else
			cout << "Reservation ikke gyldig!" << endl;
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
		reservationsPtr->bilAfhentet();
		Bil bil = reservationsPtr->getBil();
		Kalender kalender = reservationsPtr->getKalender();

		kundePtr->makePayment(kalender, bil);
	}
	else
		cout << "You dun goofed!" << endl;
}

void Reception::bilAfleveret(string etRegNr)
{
	Bil* bilPtr = findBilStation(etRegNr);
	if (bilPtr != nullptr)
	{
		Reservation* reservationsPtr = findReservation(*bilPtr);
		if (reservationsPtr != nullptr)
		{
			gamleReservationer.push_back(*reservationsPtr);
			bilPtr->makeAvailable();
			sletReservation(*reservationsPtr);	
		}
		else
			cout << "Reservationen findes ikke. You dun goofed" << endl;
	}
}

void Reception::flytBil(string etRegNr)
{
	Bil* bilPtr = stationer[currentStation].findBilStation(etRegNr);

	if (bilPtr != nullptr)
	{
		stationer[currentStation].sletBilStation(*bilPtr);
		inventory.push_back(*bilPtr);
		bilPtr->makeUnavailable();
	}
	else
		cout << "Bil ikke fundet. You dun goofed!" << endl;
}

void Reception::modtagBil(string etRegNr)
{
	Bil* bilPtr = findBilFirma(etRegNr);

	if (bilPtr != nullptr)
	{
		sletBilFirma(*bilPtr);
		addBilStation(*bilPtr);
		bilPtr->makeAvailable();
	}
}

Kunde Reception::createKunde(string etNavn, string enAdresse, int etTlf, string enMail)
{
	return Kunde(etNavn, enAdresse, etTlf, enMail);
}

Reservation Reception::createReservation(Bil enBil, Kunde enKunde, int enStartDato, int enSlutDato)
{
	return Reservation(enBil, enKunde, enStartDato, enSlutDato);
}

void Reception::addBil(Bil enBil)
{
	inventory.push_back(enBil);
}

void Reception::addStation(Station enStation)
{
	stationer.push_back(enStation);
}

Reservation* Reception::findGammelReservation(Kunde enKunde)
{
	for (int i = 0; i < gamleReservationer.size(); i++)
	{
		if (gamleReservationer[i].getKunde().getMail() == enKunde.getMail())
			return &gamleReservationer[i];
	}
	return nullptr;
}

void Reception::addBilStation(Bil enBil)
{
	stationer[currentStation].addBil(enBil);
}

void Reception::addKunde(Kunde enKunde)
{
	kunder.push_back(enKunde);
}

void Reception::addReservation(Reservation enReservation)
{
	reservationer.push_back(enReservation);
}

void Reception::sletReservation(Reservation enReservation)
{
	for (int i = 0; i < reservationer.size(); i++)
	{
		if (enReservation.getBil().getRegNr() == reservationer[i].getBil().getRegNr())
		{
			reservationer.erase(reservationer.begin() + i);
			break;
		}
	}
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

Bil* Reception::findBilStation(string etRegNr)
{
	return stationer[currentStation].findBilStation(etRegNr);
}

Bil* Reception::findBilFirma(string etRegNr)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getRegNr() == etRegNr)
			return &inventory[i];
	}
	return nullptr;
}

void Reception::sletBilFirma(Bil enBil)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (enBil.getRegNr() == inventory[i].getRegNr())
		{
			inventory.erase(inventory.begin() + i);
			break;
		}
	}
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

Reservation* Reception::findReservation(Bil enBil)
{
	for (int i  = 0; i < reservationer.size(); i++)
	{
		if (reservationer[i].getBil().getRegNr() == enBil.getRegNr())
			return &reservationer[i];
	}
	return nullptr;
}



Reception::~Reception()
{
}
