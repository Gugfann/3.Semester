#include "Dato.h"


using namespace std;

Dato::Dato()
{
}

Dato::Dato(int enD)
{
	datoen = enD;

}

void Dato::print()
{
	cout << datoen << endl;
}


int Dato::getAar()
{
	return datoen / 10000; // smider 4 cifre væk 2015 (09 04)
}

int Dato::getMaaned()
{
	return datoen / 100 % 100;
}

int Dato::getDag()
{
	return datoen % 100;
}

int Dato::getKvartal()
{
	return (getMaaned() - 1) / 3 + 1;
}

string Dato::getKvartalsNavn()
{
	string kvartaler[] = { "Januar", "April", "Juli", "Oktober" };
	return kvartaler[getKvartal() - 1];
}

string Dato::skrivMaaned()
{
	string maaneder[] = { "Januar", "Februar", "Marts", "April", "Maj", "Juni", "Juli", "August", "September", "Oktober", "November", "December" };
	return maaneder[getMaaned() - 1];
}

int Dato::getUgedag()
{
	float ugedag;
	int gaussMaaned[] = { 11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int maaned = 2.6 * gaussMaaned[getMaaned()] - 0.2;
	int maanedsTabelNorm[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
	int maanedsTabelSkud[] = { 6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };

	ugedag = (getDag() + maaned + 5 * (getAar() - 1) % 4 + 4*(getAar() - 1) % 100 + 6 * (getAar() - 1) % 400) % 7;


	return ugedag;
}

void Dato::udskrivKvartalsNavne()
{
	string kvartaler[] = { "Januar", "April", "Juli", "Oktober" };
	for (int i = 0; i < 4; i++)
		cout << kvartaler[i] << endl;
}

bool Dato::skudAar()
{
	if (getAar() % 400 == 0)
		return true;
	else
		if (getAar() % 100 == 0)
			return false;
		else
			if (getAar() % 4 == 0)
				return true;
			else
				return false;
}

string Dato::skrivBoolean(bool enB)
{
	string svar;
	if (enB == true)
		svar = "Ja! Gu' helvede er det da det, din fe'e abe!";
	else
		svar = "Nej, det er jo pis det du kommer med!";
	return svar;
}

bool Dato::validate()
{
	int dageIMaaned[] = { 31, dageIFebruar(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Hvis måneden er mindre end 1 eller større end 12, hvis dagen er mindre end 1 eller større end hvad der er muligt for den pågældende måned, eller hvis datoen ikke er på 8 cifre, så returnerer validate() false.

	if (getMaaned() < 1 || getMaaned() > 12 || getDag() < 1 || getDag() > dageIMaaned[ getMaaned() - 1 ] || datoLaengde() != 8)
		return false;
	else
		return true;
}

int Dato::datoLaengde()
{
	int laengde = 0;
	int tempDato = datoen;

	while (tempDato != 0)
	{
		tempDato /= 10;
		laengde++;
	}

	return laengde;
}

int Dato::dageIFebruar()
{
	if (skudAar() == true)
		return 29;
	else
		return 28;
}

int Dato::dagIAaret()
{
	int dage = 0;
	int dageIMaaned[] = { 31, dageIFebruar(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < getMaaned() - 1; i++)
		dage += dageIMaaned[i];
	dage += getDag();
	return dage;
}

int Dato::getDato()
{
	return datoen;
}

void Dato::setDato(int enDato)
{
	datoen = enDato;
}

void Dato::printDato()
{
	cout << getDag() << "/" << getMaaned() << " " << getAar();
}

int Dato::gauss(int aar)
{
	return (1 + (aar - 1) % 4 + 4 * (aar - 1) % 100 + 6 * (aar - 1) % 400) % 7;
}

int Dato::operator-(Dato enDato)
{
	if (getAar() > enDato.getAar())
	{
		int forskel = getAar() - enDato.getAar();
		int aar = 0;
		int temp = enDato.getDato();
		for (int i = 1; i < forskel; i++)
		{
			enDato.setDato(		((enDato.getDato() / 10000) + i) * 10000	); // næste år for startdato

			if (enDato.skudAar())
				aar += 366;
			else
				aar += 365;
		}
		
		enDato.setDato(temp);
		int restDage = 365 - enDato.dagIAaret();

		

		return dagIAaret() + restDage + aar;
	}
	if(getAar() == enDato.getAar() && getMaaned() >= enDato.getMaaned())
		return dagIAaret() - enDato.dagIAaret();

	return -1;
}

Dato Dato::operator+(int etTal)
{
	int temp = datoen;
	for (int i = 0; i < etTal; i++)
	{
		datoen++;
		if (!validate())
		{
			datoen = (datoen / 100) + 1; // næste måned
			datoen = (datoen * 100) + 1; // start fra første dag
			if (!validate())
			{
				datoen = (datoen / 10000) + 1; //næste aar
				datoen = (datoen * 100) + 1; // start fra første måned
				datoen = (datoen * 100) + 1; // start fra første dag
			}
		}
	}
	Dato returDato(datoen);
	datoen = temp;
	return returDato;
}

Dato::~Dato()
{
}

