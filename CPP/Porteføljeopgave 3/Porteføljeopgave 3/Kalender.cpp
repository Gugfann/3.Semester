#include "Kalender.h"



Kalender::Kalender()
{
}

Kalender::Kalender(int enStartDato, int enSlutDato)
{
	Dato temp1 = createDate(enStartDato);
	Dato temp2 = createDate(enSlutDato);

	if (temp1.validate() && temp2.validate())
	{
		valid = true;
		insertDates(temp1, temp2);
	}
	else
	{
		cout << "Det er jo en falsk dato!" << endl;
		valid = false;
	}
}

Dato Kalender::createDate(int enDato)
{
	return Dato(enDato);
}

void Kalender::insertDates(Dato enStartDato, Dato enSlutDato)
{
	int antalDage = enSlutDato - enStartDato; 
	if (antalDage > 0)
	{
		vector<Dato> temp;
		for (int i = 0; i < antalDage; i++)
		{
			Dato nextDate = enStartDato + i;
			if (availability(nextDate))
			{
				temp.push_back(nextDate);
			}
			else
			{
				cout << "Datoen er optaget!" << endl;
				valid = false;
				break;
			}
		}

		temp.push_back(enSlutDato);

		if (valid)
		{
			for (int i = 0; i < temp.size(); i++)
			{
				reservedDates.push_back(temp[i]);
			}
		}
	}
	else
	{
		cout << "Slutdato kommer før startdato - det er jo sort, sømand!" << endl;
		valid = false;
	}
}

bool Kalender::availability(Dato enDato)
{
	for (int i = 0; i < reservedDates.size(); i++)
	{
		if (reservedDates[i].getAar() == enDato.getAar() && reservedDates[i].getMaaned() == enDato.getMaaned() && reservedDates[i].getDag() == enDato.getDag())
			return false;
	}
	return true;
}

bool Kalender::isValid()
{
	return valid;
}

void Kalender::mergeKalender(Kalender enKalender)
{
	for (int i = 0; i < enKalender.getDates().size(); i++)
	{
		reservedDates.push_back(enKalender.getDates()[i]);
	}
}

vector<Dato> Kalender::getDates()
{
	return reservedDates;
}

void Kalender::printTakenDates()
{
	for (int i = 0; i < reservedDates.size(); i++)
	{
		cout << i + 1 << ". ";
		reservedDates[i].printDato();
		cout << endl;
	}
}


Kalender::~Kalender()
{
}
