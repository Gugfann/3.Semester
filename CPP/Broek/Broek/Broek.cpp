#include "Broek.h"



Broek::Broek()
{
}

Broek::Broek(int enT, int enN):
	taeller(enT), naevner(enN)
{
}

int Broek::getTaeller()
{
	return taeller;
}

int Broek::getNaevner()
{
	return naevner;
}

Broek Broek::adder(Broek enB)
{
	int	faellesN = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getNaevner() + enB.getTaeller()*getNaevner();
	Broek nyBroeak(nyTaeller, faellesN);
	return nyBroeak;
}

Broek Broek::subtraher(Broek enB)
{
	int	faellesN = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getNaevner() - enB.getTaeller()*getNaevner();
	Broek nyBroeak(nyTaeller, faellesN);
	return nyBroeak;
}

Broek Broek::multiplicer(Broek enB)
{
	int	nyNaevner = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getTaeller();
	Broek nyBroeak(nyTaeller, nyNaevner);
	return nyBroeak;
}

Broek Broek::divider(Broek enB)
{
	int	nyNaevner = getNaevner() * enB.getTaeller();
	int nyTaeller = getTaeller() * enB.getNaevner();
	Broek nyBroeak(nyTaeller, nyNaevner);
	return nyBroeak;
}

Broek Broek::operator+(Broek enB)
{
	int	faellesN = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getNaevner() + enB.getTaeller()*getNaevner();
	Broek nyBroeak(nyTaeller, faellesN);
	return nyBroeak;
}

Broek Broek::operator-(Broek enB)
{
	int	faellesN = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getNaevner() - enB.getTaeller()*getNaevner();
	Broek nyBroeak(nyTaeller, faellesN);
	return nyBroeak;
}

Broek Broek::operator*(Broek enB)
{
	int	nyNaevner = getNaevner() * enB.getNaevner();
	int nyTaeller = getTaeller() * enB.getTaeller();
	Broek nyBroeak(nyTaeller, nyNaevner);
	return nyBroeak;
}

Broek Broek::operator/(Broek enB)
{
	int	nyNaevner = getNaevner() * enB.getTaeller();
	int nyTaeller = getTaeller() * enB.getNaevner();
	Broek nyBroeak(nyTaeller, nyNaevner);
	return nyBroeak;
}


Broek::~Broek()
{
}
