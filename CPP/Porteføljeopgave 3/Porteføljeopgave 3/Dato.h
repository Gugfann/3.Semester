#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dato
{
public:
	Dato();
	Dato(int enD);
	void print();
	int getAar();
	int getMaaned();
	int getDag();
	int getKvartal();
	int getUgedag();
	int dagIAaret();

	int getDato();
	void setDato(int enDato);
	void printDato();

	int gauss(int aar);

	int operator-(Dato enDato);
	Dato operator+(int etTal);

	bool skudAar();
	bool validate();
	string getKvartalsNavn();
	string skrivMaaned();
	string skrivBoolean(bool enB);
	int dageIFebruar();
	int datoLaengde();
	void udskrivKvartalsNavne();


	~Dato();
private:
	int datoen;
};

