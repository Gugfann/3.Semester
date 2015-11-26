#include "Kunde.h"



Kunde::Kunde()
{
}

Kunde::Kunde(string etNavn, string enAdresse, int etTlf, string enMail):
	navn(etNavn), adresse(enAdresse), tlf(etTlf), mail(enMail)
{
}

string Kunde::getMail()
{
	return mail;
}

void Kunde::makePayment(Kalender enKalender, Bil enBil)
{
	betaling = createPayment(enKalender,enBil);
}

Payment Kunde::createPayment(Kalender enKalender, Bil enBil)
{
	return Payment(enKalender,enBil);
}


Kunde::~Kunde()
{
}
