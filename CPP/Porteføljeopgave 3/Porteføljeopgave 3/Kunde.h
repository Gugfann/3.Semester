#pragma once
#include <string>
#include "Payment.h"
#include "Kalender.h"
#include "Bil.h"

using namespace std;

class Kunde
{
public:
	Kunde();
	Kunde(string etNavn, string enAdresse, int etTlf, string enMail);
	string getMail();

	void makePayment(Kalender enKalender, Bil enBil);
	Payment createPayment(Kalender enKalender, Bil enBil);

	~Kunde();
protected:
	string navn;
	string adresse;
	int tlf;
	string mail;
	Payment betaling;
};

