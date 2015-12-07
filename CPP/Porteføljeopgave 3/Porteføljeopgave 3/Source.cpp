#include "Reception.h"
#include "Dato.h"


int main()
{
	Reception lobby; 
	Station her;

	lobby.addStation(her);

	lobby.opretKunde("Gorm Adolf", "Hans Tausensgade 117", 12345678, "frelsth�vner@arto.dk");
	lobby.opretKunde("Bjarne Lemming", "H.C. Andersens Boulevard 2", 28374615, "dj�velskgnu@hotmail.com");
	lobby.opretKunde("Brit Dorit", "Albanigade 13", 27654310, "lumskpanda@jubii.dk");
	lobby.opretKunde("Jarl Dingo", "Niels Bohr's All� 1", 34928165, "olmkrage@gmail.com");

	Bil mercedes("Smadrekassen");
	Bil fiat("Kunstv�rket");
	Bil skoda("Damemagneten");
	Bil mitsubishi("Flagskibet");
	Bil chevrolet("Den flyvende holl�nder");

	lobby.addBil(mercedes);
	lobby.addBil(fiat);
	lobby.addBil(skoda);
	lobby.addBil(mitsubishi);
	lobby.addBil(chevrolet);

	lobby.modtagBil("Smadrekassen");
	lobby.modtagBil("Kunstv�rket");
	lobby.modtagBil("Damemagneten");
	lobby.modtagBil("Flagskibet");
	lobby.modtagBil("Den flyvende holl�nder");

	lobby.makeReservation("lumskpanda@jubii.dk", "Flagskibet", 19870905, 19871001);
	lobby.makeReservation("olmkrage@gmail.com", "Flagskibet", 20010513, 20010602);
	lobby.makeReservation("frelsth�vner@arto.dk", "Flagskibet", 20010603, 20010608);
	lobby.makeReservation("dj�velskgnu@hotmail.com", "Flagskibet", 20010814, 20010908);
	lobby.makeReservation("olmkrage@gmail.com", "Flagskibet", 20020217, 20020602);

	lobby.hentBil("lumskpanda@jubii.dk");
	lobby.bilAfleveret("Flagskibet");

	lobby.hentBil("olmkrage@gmail.com");
	lobby.bilAfleveret("Flagskibet");

	lobby.hentBil("frelsth�vner@arto.dk");

	lobby.getStationer()[0].findBilStation("Flagskibet")->getKalender().printTakenDates();

	lobby.makeReservation("lumskpanda@jubii.dk","Flagskibet",20010528,20010604);

	lobby.makeReservation("dj�velskgnu@hotmail.com", "Smadrekassen", 20010814, 20010908);

	return 0;
}