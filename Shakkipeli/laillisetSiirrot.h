#ifndef LAILLISETSIIRROT_H
#define LAILLISETSIIRROT_H

#include <list>
#include "asema.h"
#include "ruutu.h"
#include <vector>

	void annaTorninLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );
	void annaLahetinLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );
	void annaDaaminLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );

	void annaKuninkaanLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );
	void annaRatsunLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );
	void annaSotilaanLaillisetSiirrot(vector<Siirto*>* lista, Ruutu*, Asema*, int );
	void annaLinnoituksenLaillisetSiirrot(Siirto *);

	bool onkoRuutuUhattu(Asema *, int);

	void luoLaillisetSiirrotLista(vector<Siirto*> *, Asema *);

	void huolehdiKuninkaanShakeista();

#endif