#pragma once
#include "Dyr.h"
#include "Horn.h"
#include "Kaengurustylte.h"
#include "Aldi.h"
class Bjergged :																				// Arv
	public Dyr
{
public:
	Bjergged();

	void hop() {																				// Overload
		if (hemmeligStylte == nullptr) { cout << "Hop vildere!" << endl; }

		else { cout << "Hop helt tosset!" << endl; }
	};

	void kaengurustylteUpgrade(Kaengurustylte &nyStylte) { hemmeligStylte = &nyStylte; };

	void findStylte(Aldi minLokaleAldi) { minLokaleAldi.kigPaaStylte(); };						// Association

	~Bjergged();
protected:
	Horn mitHorn;																				// Hård aggregering
private:
	Kaengurustylte* hemmeligStylte{ nullptr };													// Blød aggregering
};

