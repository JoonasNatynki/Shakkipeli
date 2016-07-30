#ifndef ssss
#define ssss

#include "minMax.h"
#include "asema.h"
#include <algorithm>
using namespace std;

extern Asema * lauta_s;
extern vector<Siirto*> * lailliset_siirrot_s;
extern Siirto * siirto_s;


class Pelipuu {
public:
	MinMaxPaluu maxi(int syvyys, Asema asema);
	MinMaxPaluu mini(int syvyys, Asema asema);
};

MinMaxPaluu Pelipuu::maxi(int depth, Asema temp_lauta)
{
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (depth == 0) {
		MinMaxPaluu result;
		result.evaluointiArvo = abs(evaluoi(temp_lauta));
		return result;
	};
	int max = 0;

	vector<Siirto*> siirrot_tmp;
	luoLaillisetSiirrotLista(&siirrot_tmp, &temp_lauta);

	int score;
	int siirtoNum = 0;
	vector<int> equal_moves_array;
	MinMaxPaluu result;

	for (int x = 0; x < siirrot_tmp.size(); x++)
	{
		temp_lauta.paivitaAsema(siirrot_tmp.at(x), true);
		temp_lauta.setSiirtoVuoro(-1);

		result = mini(depth - 1, temp_lauta);
		score = abs(result.evaluointiArvo);

		if (score == max)
		{
			equal_moves_array.push_back(x);
		}else if (score > max)
		{
			max = score;
			siirtoNum = x;
		}
	}
	if (equal_moves_array.size() > 0)
	{
		int chosen = rand() % equal_moves_array.size();
		siirtoNum = equal_moves_array.at(chosen);
	}

	result.evaluointiArvo = max;
	result.parasSiirto = *siirrot_tmp.at(siirtoNum);

	return result;
}

MinMaxPaluu Pelipuu::mini(int depth, Asema temp_lauta)
{
	// Tarkasta onko matti tai patti, jos on niin poistu asap, matti -100000, patti 0
	if (depth == 0) {
		MinMaxPaluu result;
		result.evaluointiArvo = abs(evaluoi(temp_lauta));
		return result;
	};
	int min = 0;

	vector<Siirto*> siirrot_tmp;
	luoLaillisetSiirrotLista(&siirrot_tmp, &temp_lauta);

	int score;
	vector<int> equal_moves_array;
	int siirtoNum = 0;
	MinMaxPaluu result;

	for (int x = 0; x < siirrot_tmp.size(); x++)
	{
		temp_lauta.paivitaAsema(siirrot_tmp.at(x), true);
		temp_lauta.setSiirtoVuoro(1);

		result = maxi(depth - 1, temp_lauta);
		score = result.evaluointiArvo * (-1);

		if (score == min)
		{
			equal_moves_array.push_back(x);
		}else if (score < min)
		{
			min = score;
			siirtoNum = x;
		}

	}
	if (equal_moves_array.size() > 0)
	{
		int chosen = rand() % equal_moves_array.size();
		siirtoNum = equal_moves_array.at(chosen);
	}

	result.evaluointiArvo = min;
	result.parasSiirto = *siirrot_tmp.at(siirtoNum);

	for (int x = 0; x < siirrot_tmp.size(); x++)
		delete siirrot_tmp.at(x);

	return result;
}

#endif