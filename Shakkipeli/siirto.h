#ifndef SIIRTO_H
#define SIIRTO_H

#include "ruutu.h"

class Siirto {
public:

	Siirto(Ruutu, Ruutu);
	Siirto() {}
	Siirto(bool, bool); // Poikkeus siirto linnoitusta varten
	~Siirto() {}

	Ruutu * getAlkuruutu();
	Ruutu * getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitkaLinna();

private:
	Ruutu alkuRuutu;
	Ruutu loppuRuutu;
	int miksiKorotetaan = 0;
	bool lyhytLinna = false;
	bool pitkaLinna = false;
};
#endif