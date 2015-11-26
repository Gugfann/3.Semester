#pragma once
#include "Kalender.h"
#include "Bil.h"

class Payment
{
public:
	Payment();
	Payment(Kalender enKalender, Bil enBil);
	~Payment();
protected:
	float totalAmount;
};

