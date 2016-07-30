#include "evaluonti.h"
//#include "main.h"


double evaluoi(Asema lauta)
{
	int siirtoVuoro = lauta.getSiirtoVuoro();

	return laskeNappuloidenArvo(&lauta, siirtoVuoro) + nappuloitaKeskella(&lauta, siirtoVuoro) + linjat(&lauta, siirtoVuoro);
}

double laskeNappuloidenArvo(Asema * lauta, int vari)
{
	double arvo = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta->lauta[x][y] != NULL)
			{
				if (lauta->lauta[x][y]->getNimi() == L"vd" && vari == 1) { arvo = arvo + 9; }
				if (lauta->lauta[x][y]->getNimi() == L"md" && vari == -1) { arvo = arvo - 9; }

				if (lauta->lauta[x][y]->getNimi() == L"vt" && vari == 1) { arvo = arvo + 5; }
				if (lauta->lauta[x][y]->getNimi() == L"mt" && vari == -1) { arvo = arvo - 5; }

				if (lauta->lauta[x][y]->getNimi() == L"vl" && vari == 1) { arvo = arvo + 3.25; }
				if (lauta->lauta[x][y]->getNimi() == L"ml" && vari == -1) { arvo = arvo - 3.25; }

				if (lauta->lauta[x][y]->getNimi() == L"vr" && vari == 1) { arvo = arvo + 3; }
				if (lauta->lauta[x][y]->getNimi() == L"mr" && vari == -1) { arvo = arvo - 3; }

				if (lauta->lauta[x][y]->getNimi() == L"vs" && vari == 1) { arvo = arvo + 1; }
				if (lauta->lauta[x][y]->getNimi() == L"ms" && vari == -1) { arvo = arvo - 1; }

			}
		}
	}
	return arvo;
}

bool onkoAvausTaiKeskipeli(Asema * lauta, int vari)
{
	int arvo = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta->lauta[x][y] != NULL)
			{
				if (lauta->lauta[x][y]->getNimi() == L"vs" && vari == 1) { arvo++; }
				if (lauta->lauta[x][y]->getNimi() == L"ms" && vari == -1) { arvo = arvo - 1; }
			}
		}
	}
	if (abs(arvo) > 8) { return true; } else { return false; }
}

double nappuloitaKeskella(Asema * lauta, int vari)
{
	double arvo = 0;

	for (int x = 2; x < 6; x++)
	{
		for (int y = 2; y < 6; y++)
		{
			if (lauta->lauta[x][y] != NULL)
			{
				if (lauta->lauta[x][y]->getNimi() == L"vr" && vari == 1) { arvo = arvo + 3; }
				if (lauta->lauta[x][y]->getNimi() == L"mr" && vari == -1) { arvo = arvo - 3; }

				if (lauta->lauta[x][y]->getNimi() == L"vs" && vari == 1) { arvo = arvo + 1; }
				if (lauta->lauta[x][y]->getNimi() == L"ms" && vari == -1) { arvo = arvo - 1; }
			}
		}
	}
	return arvo;
}

double linjat(Asema * lauta, int vari)
{
	int arvo = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (lauta->lauta[x][y] != NULL)
			{
				if (lauta->lauta[x][y]->getNimi() == L"vd" && vari == 1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaDaaminLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0 )
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}
				if (lauta->lauta[x][y]->getNimi() == L"md" && vari == -1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaDaaminLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0)
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}

				if (lauta->lauta[x][y]->getNimi() == L"vt" && vari == 1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaTorninLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0)
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}
				if (lauta->lauta[x][y]->getNimi() == L"mt" && vari == -1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaTorninLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0)
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}

				if (lauta->lauta[x][y]->getNimi() == L"vl" && vari == 1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaLahetinLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0)
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo + abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}
				if (lauta->lauta[x][y]->getNimi() == L"ml" && vari == -1)
				{
					vector<Siirto*> * asdf = new vector<Siirto*>;
					annaLahetinLaillisetSiirrot(asdf, new Ruutu(x, y), lauta, vari);

					for (int x = 0; x < asdf->size(); x++)
					{
						if (abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi()) > 0)
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getRivi() - asdf->at(x)->getAlkuruutu()->getRivi());
						}
						else
						{
							arvo = arvo - abs(asdf->at(x)->getLoppuruutu()->getSarake() - asdf->at(x)->getAlkuruutu()->getSarake());
						}
					}
					delete asdf;
				}
			}
		}
	}
	return arvo;
}