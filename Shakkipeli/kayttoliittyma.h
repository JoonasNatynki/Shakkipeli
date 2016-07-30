#ifndef KAYTTOLIITTYMA_H
#define KAYTTOLIITTYMA_H

#include "asema.h"

class Kayttoliittyma {
public:
	Asema * asema;
	Kayttoliittyma(Asema * asema);
	Siirto * annaVastustajanSiirto();
	void piirraLauta(wstring, wstring);
	void piirraLauta(wstring);
	void piirraLauta();
	void printText(wstring);
	int kysyVastustajanVari();

};
#endif