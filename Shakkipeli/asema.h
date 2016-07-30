#ifndef ASEMA_H
#define ASEMA_H

#include "nappula.h"
#include "siirto.h"

class Asema {

private:
	int siirtoVuoro;
	bool onkoValkeaKuningasLiikkunut;
	bool onkoMustaKuningasLiikkunut;
	bool onkoValkeaDTliikkunut;
	bool onkoValkeaKTliikkunut;
	bool onkoMustaDTliikkunut;
	bool onkoMustaKTliikkunut;

public:
	//Konstruktori luo alkuaseman laudalle
	//Valkea v‰ri = 0, musta v‰ri = 1
	Asema();

	Nappula * lauta[8][8]; //varaa muistia objekteille, ei viel‰ luo niit‰


	//luodaan nappuloiden tyypit ja varataan niille muistista pointterit
	//new luonti tehd‰‰n konstruktorissa Asema() .cpp filussa
	Nappula * vt; //tornit
	Nappula * mt;

	Nappula * vh; //hevoset
	Nappula * mh;

	Nappula * vl; //l‰hetit
	Nappula * ml;

	Nappula * vk; //kuninkaat
	Nappula * mk;

	Nappula * vd; //daamit
	Nappula * md;

	Nappula * vs; //sotilaat
	Nappula * ms;

	~Asema() {}

	void paivitaAsema(Siirto*, bool);
	const int getSiirtoVuoro();
	void setSiirtoVuoro(int);
	const bool getOnkoValkeaKuningasLiikkunut();
	const bool getOnkoMustaKuningasLiikkunut();
	const bool getOnkoValkeaDTliikkunut();
	const bool getOnkoValkeaKTliikkunut();
	const bool getOnkoMustaDTliikkunut();
	const bool getOnkoMustaKTliikkunut();
};
#endif