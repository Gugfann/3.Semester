#pragma once
class Kalender
{
public:
	Kalender();
	Kalender(int enStartDato, int enSlutDato);
	~Kalender();
protected:
	int startDato;
	int slutDato;
};

