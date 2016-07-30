#include "asema.h"
#include "kayttoliittyma.h"
#include <iostream>
#include <vector>
#include "history.h"

extern Kayttoliittyma * os_s;
extern vector<History*> * siirto_historia_s;
extern int nappuloita_syöty;

Asema::Asema()
{
	vt = new Nappula(L"vt", L"\u2656", 1);
	mt = new Nappula(L"mt", L"\u265C", -1);

	vh = new Nappula(L"vr", L"\u2658", 1);
	mh = new Nappula(L"mr", L"\u265E", -1);

	vl = new Nappula(L"vl", L"\u2657", 1);
	ml = new Nappula(L"ml", L"\u265D", -1);

	vk = new Nappula(L"vk", L"\u2654", 1);
	mk = new Nappula(L"mk", L"\u265A", -1);

	vd = new Nappula(L"vd", L"\u2655", 1);
	md = new Nappula(L"md", L"\u265B", -1);

	vs = new Nappula(L"vs", L"\u2659", 1);
	ms = new Nappula(L"ms", L"\u265F", -1);

	//we set the variables to initial states
	siirtoVuoro = 1;
	onkoValkeaKuningasLiikkunut = false;
	onkoMustaKuningasLiikkunut = false;
	onkoValkeaDTliikkunut = false;
	onkoValkeaKTliikkunut = false;
	onkoMustaDTliikkunut = false;
	onkoMustaKTliikkunut = false;

	for (int x = 0; x < 8; x++) //x row
	{
		for (int y = 0; y < 8; y++) //y row
		{
			lauta[x][y] = NULL;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		lauta[i][1] = vs;
	}

	for (int i = 0; i < 8; i++)
	{
		lauta[i][6] = ms;
	}

	//ERASE THIS, TESTING ONLY
	//lauta[4][1] = NULL;
	//########################

	lauta[0][0] = vt;
	lauta[1][0] = vh;
	lauta[2][0] = vl;
	lauta[3][0] = vd;
	lauta[4][0] = vk;
	lauta[5][0] = vl;
	lauta[6][0] = vh;
	lauta[7][0] = vt;





	lauta[0][7] = mt;
	lauta[1][7] = mh;
	lauta[2][7] = ml;
	lauta[3][7] = md;
	lauta[4][7] = mk;
	lauta[5][7] = ml;
	lauta[6][7] = mh;
	lauta[7][7] = mt;


	//REMOVE THIS, THIS IS USED FOR DEBUGGING
	//lauta[2][6] = NULL;
	//lauta[2][3] = ms;
	//#######################################
}

void Asema::paivitaAsema(Siirto * siirto, bool simulation)
{

	if (!siirto->onkoLyhytLinna() && !siirto->onkoPitkaLinna())
	{
		if (lauta[siirto->getAlkuruutu()->getSarake()][siirto->getAlkuruutu()->getRivi()] == NULL)
		{
			
		}
		else
		{
			Nappula * nabula = lauta[siirto->getAlkuruutu()->getSarake()][siirto->getAlkuruutu()->getRivi()]; //we get the nabula that is in lauta[x][y]

			lauta[siirto->getAlkuruutu()->getSarake()][siirto->getAlkuruutu()->getRivi()] = NULL; //we set the old ruutu as NULL as the nabula will move away from it

			//nabulan syönti siinä ruudulla mihin liikutaan
			if (lauta[siirto->getLoppuruutu()->getSarake()][siirto->getLoppuruutu()->getRivi()] != NULL && simulation == false)
			{
				//syö nabula
				nappuloita_syöty++;
				siirto_historia_s->at(siirto_historia_s->size() - 1)->nabula_h = lauta[siirto->getLoppuruutu()->getSarake()][siirto->getLoppuruutu()->getRivi()];
			}

			lauta[siirto->getLoppuruutu()->getSarake()][siirto->getLoppuruutu()->getRivi()] = nabula;

			if ((nabula->getNimi() == L"vt") && !onkoValkeaKTliikkunut && (siirto->getAlkuruutu()->getRivi() == 0 && siirto->getAlkuruutu()->getSarake() == 7))
			{
				onkoValkeaKTliikkunut = true;
			}
			if ((nabula->getNimi() == L"mt") && !onkoMustaKTliikkunut && siirto->getAlkuruutu()->getRivi() == 7 && siirto->getAlkuruutu()->getSarake() == 7)
			{
				onkoMustaKTliikkunut = true;
			}
			if ((nabula->getNimi() == L"vt") && !onkoValkeaDTliikkunut && siirto->getAlkuruutu()->getRivi() == 0 && siirto->getAlkuruutu()->getSarake() == 0)
			{
				onkoValkeaDTliikkunut = true;
			}
			if ((nabula->getNimi() == L"mt") && !onkoMustaDTliikkunut && siirto->getAlkuruutu()->getRivi() == 0 && siirto->getAlkuruutu()->getSarake() == 7)
			{
				onkoMustaDTliikkunut = true;
			}
			if ((nabula->getNimi() == L"vk") && !onkoValkeaKuningasLiikkunut)
			{
				onkoValkeaKuningasLiikkunut = true;
			}
			if ((nabula->getNimi() == L"mk") && !onkoMustaKuningasLiikkunut)
			{
				onkoMustaKuningasLiikkunut = true;
			}
		}
	}

	//JOS ON KYSEESSÄ LINNOITUS, TEE TÄMÄ
	if (siirto->onkoLyhytLinna() || siirto->onkoPitkaLinna())
	{
		//who's turn it is?
		os_s->asema->getSiirtoVuoro() == 1 ? onkoValkeaKuningasLiikkunut = true : onkoMustaKuningasLiikkunut = true;
		//if white, move pieces
		if (os_s->asema->getSiirtoVuoro() == 1 && siirto->onkoLyhytLinna())
		{
			lauta[7][0] = NULL;
			lauta[4][0] = NULL;

			lauta[6][0] = vk;
			lauta[5][0] = vt;
		}
		
	}
}

const int Asema::getSiirtoVuoro()
{
	return siirtoVuoro;
}

void Asema::setSiirtoVuoro(int x)
{
	siirtoVuoro = x;
}

const bool Asema::getOnkoValkeaKuningasLiikkunut()
{
	return onkoValkeaKuningasLiikkunut;
}

const bool Asema::getOnkoMustaKuningasLiikkunut()
{
	return onkoMustaKuningasLiikkunut;
}

const bool Asema::getOnkoValkeaDTliikkunut()
{
	return onkoValkeaDTliikkunut;
}

const bool Asema::getOnkoValkeaKTliikkunut()
{
	return onkoValkeaKTliikkunut;
}

const bool Asema::getOnkoMustaDTliikkunut()
{
	return onkoMustaDTliikkunut;
}

const bool Asema::getOnkoMustaKTliikkunut()
{
	return onkoMustaKTliikkunut;
}
