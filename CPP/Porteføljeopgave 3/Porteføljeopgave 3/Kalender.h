#pragma once
#include "Dato.h"
#include <vector>
using namespace std;
class Kalender
{
public:
	Kalender();
	Kalender(int enStartDato, int enSlutDato);
	Dato createDate(int enDato);
	void insertDates(Dato enStartDato, Dato enSlutDato);
	bool availability(Dato enDato);
	bool isValid();
	void mergeKalender(Kalender enKalender);
	vector<Dato> getDates();
	void printTakenDates();
	~Kalender();
protected:
	vector<Dato> reservedDates;
	bool valid;
};

