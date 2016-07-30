#include "siirto.h"

Siirto::Siirto (Ruutu alkuruutu, Ruutu loppuruutu) : alkuRuutu(alkuruutu), loppuRuutu(loppuruutu) 
{
	lyhytLinna = false;
	pitkaLinna = false;
}

Siirto::Siirto ( bool onkoLyhytLinna, bool onkoPitkaLinna )
{
	lyhytLinna = onkoLyhytLinna;
	pitkaLinna = onkoPitkaLinna;
}

Ruutu * Siirto::getAlkuruutu ()
{
	return &alkuRuutu;
}

Ruutu * Siirto::getLoppuruutu ()
{
	return &loppuRuutu;
}

bool Siirto::onkoLyhytLinna ()
{
	return lyhytLinna;
}

bool Siirto::onkoPitkaLinna ()
{
	return pitkaLinna;
}

