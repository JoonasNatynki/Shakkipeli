#include "laillisetSiirrot.h"

extern Asema * lauta_s; //the chess board singleton
extern list<Siirto> * lista_s; //list of moves made singleton
extern vector<Siirto*> * siirto_historia_s; //vector of moves for history's sake singleton
//extern int nabulan_color; //the color of the piece that moved
extern vector<Siirto*> * lailliset_siirrot_s;
extern wstring nabulan_Nimi;

void annaTorninLaillisetSiirrot(vector<Siirto*> * _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{

	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		int Y[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylöspäin menevä iteraattori
		int A[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //alaspäin menevä iteraattori
		int V[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //vasemmalle menevä iteraattori
		int O[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //oikealle menevä iteraattori
		bool breik[4] = { false, false, false, false }; //we use this to see if while loop is supposed to break. Will get all trues when there are no legit moves left to iterate through

		while ((!breik[0] == true || !breik[1] == true || !breik[2] == true || !breik[3] == true))
		{
			//stay within the board and iterate through
			Y[1] != 7 && !breik[0] ? Y[1]++ : breik[0] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			A[1] != 0 && !breik[1] ? A[1]-- : breik[1] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			V[0] != 0 && !breik[2] ? V[0]-- : breik[2] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			O[0] != 7 && !breik[3] ? O[0]++ : breik[3] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			//If the square is empty, push it into the list.
			_lauta->lauta[Y[0]][Y[1]] != NULL && _lauta->lauta[Y[0]][Y[1]]->getVari() != _vari && !breik[0] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(Y[0], Y[1]))), breik[0] = true) : Y[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[Y[0]][Y[1]] == NULL && !breik[0] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(Y[0], Y[1]))) : breik[0] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[A[0]][A[1]] != NULL && _lauta->lauta[A[0]][A[1]]->getVari() != _vari && !breik[1] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(A[0], A[1]))), breik[1] = true) : A[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[A[0]][A[1]] == NULL && !breik[1] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(A[0], A[1]))) : breik[1] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[V[0]][V[1]] != NULL && _lauta->lauta[V[0]][V[1]]->getVari() != _vari && !breik[2] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(V[0], V[1]))), breik[2] = true) : V[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[V[0]][V[1]] == NULL && !breik[2] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(V[0], V[1]))) : breik[2] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[O[0]][O[1]] != NULL && _lauta->lauta[O[0]][O[1]]->getVari() != _vari && !breik[3] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(O[0], O[1]))), breik[3] = true) : O[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[O[0]][O[1]] == NULL && !breik[3] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(O[0], O[1]))) : breik[3] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"
		}
	}
 };

void annaLahetinLaillisetSiirrot(vector<Siirto*>* _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{
	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		int YO[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylösoikealle menevä iteraattori
		int YV[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylösvasemmalle menevä iteraattori
		int AO[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; // alasoikealle menevä iteraattori
		int AV[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //alasvasemmalle menevä iteraattori
		bool breik[4] = { false, false, false, false }; //we use this to see if while loop is supposed to break. Will get all trues when there are no legit moves left to iterate through

		while ((!breik[0] == true || !breik[1] == true || !breik[2] == true || !breik[3] == true))
		{
			//stay within the board and iterate through
			YO[1] != 7 && YO[0] != 7 && !breik[0] ? (YO[1]++, YO[0]++) : breik[0] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			YV[1] != 7 && YV[0] != 0 && !breik[1] ? (YV[1]++, YV[0]--) : breik[1] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			AO[0] != 7 && AO[1] != 0 && !breik[2] ? (AO[0]++, AO[1]--) : breik[2] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			AV[0] != 0 && AV[1] != 0 && !breik[3] ? (AV[0]--, AV[1]--) : breik[3] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			//If the square is empty, push it into the list.
			_lauta->lauta[YO[0]][YO[1]] != NULL && _lauta->lauta[YO[0]][YO[1]]->getVari() != _vari && !breik[0] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YO[0], YO[1]))), breik[0] = true) : YO[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[YO[0]][YO[1]] == NULL && !breik[0] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YO[0], YO[1]))) : breik[0] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[YV[0]][YV[1]] != NULL && _lauta->lauta[YV[0]][YV[1]]->getVari() != _vari && !breik[1] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YV[0], YV[1]))), breik[1] = true) : YV[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[YV[0]][YV[1]] == NULL && !breik[1] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YV[0], YV[1]))) : breik[1] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[AO[0]][AO[1]] != NULL && _lauta->lauta[AO[0]][AO[1]]->getVari() != _vari && !breik[2] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(AO[0], AO[1]))), breik[2] = true) : AO[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[AO[0]][AO[1]] == NULL && !breik[2] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(AO[0], AO[1]))) : breik[2] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"

			_lauta->lauta[AV[0]][AV[1]] != NULL && _lauta->lauta[AV[0]][AV[1]]->getVari() != _vari && !breik[3] ? (_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(AV[0], AV[1]))), breik[3] = true) : AV[0]; //"jos ruutu ei ole tyhjä ja se nappula mikä siinä on ei ole omaa puoluetta, siihen voi siis siirtyä....pysäytä tämä osuus seuraavalla kerralla äläkä tee sitä uudestaan"
			_lauta->lauta[AV[0]][AV[1]] == NULL && !breik[3] ? _lista->push_back(new Siirto(*_alotusRuutu, Ruutu(AV[0], AV[1]))) : breik[3] = true; //"jos ruutu on tyhjä, lisää se listaan...jos ei niin älä tee mitään ja skippaa tämä seuraavalla kerralla"
		}
	}
};

void annaDaaminLaillisetSiirrot(vector<Siirto*> * _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{
	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		//we simply call the two earlier methods to fill the list with both of the piece movement possibilities
		annaLahetinLaillisetSiirrot(_lista, _alotusRuutu, _lauta, _vari);
		annaTorninLaillisetSiirrot(_lista, _alotusRuutu, _lauta, _vari);
	}
}

void annaSotilaanLaillisetSiirrot(vector<Siirto*> * _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{
	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		int Y[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() + _vari}; //ylöspäin/alaspäin menevä iteraattori
		int YV[2] = { _alotusRuutu->getSarake() + (-_vari) , _alotusRuutu->getRivi() + _vari };
		int YO[2] = { _alotusRuutu->getSarake() + _vari, _alotusRuutu->getRivi() + _vari };



		//ENSIMMÄINEN SIIRTO TUPLAUS################################################################
		if ((_alotusRuutu->getRivi() == 1 || _alotusRuutu->getRivi() == 6) && _lauta->lauta[Y[0]][Y[1] + (1 * (_vari))] == NULL)
		{
			_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(Y[0], Y[1] + (1 * _vari)))); //double step
		};
		//##########################################################################################
		//move one square up#####################################################################
			if (_lauta->lauta[Y[0]][Y[1]] == NULL)
		{
			_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(Y[0], Y[1]))); //single step
		};
		//#######################################################################################


		
		//OHESTALYÖNTI VASEMALLE LOGIIKKA########################################################################################
		if (_lauta->lauta[YV[0]][YV[1]] == NULL && _lauta->lauta[YV[0]][YV[1] - _vari] != NULL && (YV[0] >= 0 && YV[1] >= 0 && YV[0] <= 7 && YV[1] <= 7))
		{
			if ((_lauta->lauta[YV[0]][YV[1] - _vari]->getNimi() == L"vs" || _lauta->lauta[YV[0]][YV[1] - _vari]->getNimi() == L"ms") && _lauta->lauta[YV[0]][YV[1] - _vari]->getVari() != _vari)
			{
				_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YV[0],YV[1])));
			}
		}
		//#######################################################################################################################
		//OHESTALYÖNTI OIKEALLE LOGIIKKA########################################################################################
		if (_lauta->lauta[YO[0]][YO[1]] == NULL && _lauta->lauta[YO[0]][YO[1] - _vari] != NULL && (YO[0] >=0 && YO[1] >= 0 && YO[0] <= 7 && YO[1] <= 7))
		{
			if ((_lauta->lauta[YO[0]][YO[1] - _vari]->getNimi() == L"vs" || _lauta->lauta[YO[0]][YO[1] - _vari]->getNimi() == L"ms") && _lauta->lauta[YO[0]][YO[1] - _vari]->getVari() != _vari)
			{
				_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(YO[0], YO[1])));
			}
		}
		//######################################################################################################################


	}
}

void luoLaillisetSiirrotLista(vector<Siirto*> * lailliset_siirrot_lista, Asema * asema)
{
	//LUODAAN LAILLISET SIIRROT SINGLETONI LISTA JA TÄYTETÄÄN SE#############################################################
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (asema->lauta[x][y] != NULL)
			{
				wstring name;
				name = asema->lauta[x][y]->getNimi();

				if (asema->getSiirtoVuoro() == 1) //WHITE PIECES
				{
					name == L"vt" ?
						annaTorninLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);
					name == L"vl" ?
						annaLahetinLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);
					name == L"vd" ?
						annaDaaminLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);
					name == L"vk" ?
						annaKuninkaanLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);
					name == L"vr" ?
						annaRatsunLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);
					name == L"vs" ?
						annaSotilaanLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, 1) : (nabulan_Nimi);

					/*for (int z = 0; z < lista_s->size(); z++)
					{
						//here we push the things in list lista_s to vector lailliset_siirrot.....siirto_s IS REDUNDANT AND NEEDS TO BE BRUTALLY MURDERED!!
						lailliset_siirrot_lista->push_back(lista_s->front());
						lista_s->pop_front();
					}*/
				}
				else //BLACK PIECES
				{
					name == L"mt" ?
						annaTorninLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);
					name == L"ml" ?
						annaLahetinLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);
					name == L"md" ?
						annaDaaminLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);
					name == L"mk" ?
						annaKuninkaanLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);
					name == L"mr" ?
						annaRatsunLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);
					name == L"ms" ?
						annaSotilaanLaillisetSiirrot(lailliset_siirrot_lista, &Ruutu(x, y), asema, -1) : (nabulan_Nimi);

					/*for (int z = 0; z < lista_s->size(); z++)
					{
						//here we push the things in list lista_s to vector lailliset_siirrot.....siirto_s IS REDUNDANT AND NEEDS TO BE BRUTALLY MURDERED!!
						lailliset_siirrot_lista->push_back(lista_s->front());
						lista_s->pop_front();
					}*/
				}
			}
		}
	}
	//#######################################################################################################################
}

bool onkoRuutuUhattu(Asema * asema, int vastustajanVari)
{

	vector<Siirto*> * vastustajan_lailliset_siirrot = new vector<Siirto*>;
	vastustajanVari == -1 ? asema->setSiirtoVuoro(-1) : asema->setSiirtoVuoro(1); //switch siirtovuoro temporarily so we can create the vastustajan_lailliset_siirrot
	luoLaillisetSiirrotLista(vastustajan_lailliset_siirrot, asema);
	vastustajanVari == -1 ? asema->setSiirtoVuoro(-1) : asema->setSiirtoVuoro(1); //switch siirtovuoro temporarily so we can create the vastustajan_lailliset_siirrot

	for (int x = 0; x < vastustajan_lailliset_siirrot->size(); x++)
	{
		if (vastustajanVari == 1)
		{
			if (asema->lauta[vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getSarake()][vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getRivi()] != NULL 
				&& asema->lauta[vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getSarake()][vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getRivi()]->getNimi() == L"vk")
			{
				return true;
			}
		}
		else
		{

			if (asema->lauta[vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getSarake()][vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getRivi()] != NULL && asema->lauta[vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getSarake()][vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getRivi()] != NULL 
				&& asema->lauta[vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getSarake()][vastustajan_lailliset_siirrot->at(x)->getLoppuruutu()->getRivi()]->getNimi() == L"vk")
			{
				return true;
			}
		}
	}

	return false;
}

void huolehdiKuninkaanShakeista() 
{
	Asema temp_asema = *lauta_s;

	for (int x = 0; x < lailliset_siirrot_s->size(); x++)
	{
		temp_asema.paivitaAsema( (lailliset_siirrot_s->at(x)), true);

		if (onkoRuutuUhattu( &temp_asema, lauta_s->getSiirtoVuoro() == 1 ? -1:1) ) 
		{
			lailliset_siirrot_s->erase(lailliset_siirrot_s->begin() + x);
			x = 0; // we start from the beginning of the lailliset_siirrot lista because it waas altered
		}
		temp_asema = *lauta_s; //reset board so we can cehck the other moves in lailliset_siirrot
	}
}

void annaKuninkaanLaillisetSiirrot(vector<Siirto*> * _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{
	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		int K[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //kuninkaan sijainti

		int Y[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylöspäin menevä iteraattori
		int A[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //alaspäin menevä iteraattori
		int V[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //vasemmalle menevä iteraattori
		int O[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //oikealle menevä iteraattori
		int YO[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylösoikealle menevä iteraattori
		int YV[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ylösvasemmalle menevä iteraattori
		int AO[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; // alasoikealle menevä iteraattori
		int AV[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //alasvasemmalle menevä iteraattori

		bool breik[8] = { false, false, false, false, false, false, false, false }; //we use this to see if while loop is supposed to break. Will get all trues when there are no legit moves left to iterate through

		while ((!breik[0] == true || !breik[1] == true || !breik[2] == true || !breik[3] == true || !breik[4] == true || !breik[5] == true || !breik[6] == true || !breik[7] == true))
		{
			Y[1] != 7 && !breik[0] ? Y[1]++ : breik[0] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			A[1] != 0 && !breik[1] ? A[1]-- : breik[1] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			V[0] != 0 && !breik[2] ? V[0]-- : breik[2] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			O[0] != 7 && !breik[3] ? O[0]++ : breik[3] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			//stay within the board and iterate through
			YO[1] != 7 && YO[0] != 7 && !breik[4] ? (YO[1]++, YO[0]++) : breik[4] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			YV[1] != 7 && YV[0] != 0 && !breik[5] ? (YV[1]++, YV[0]--) : breik[5] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			AO[0] != 7 && AO[1] != 0 && !breik[6] ? (AO[0]++, AO[1]--) : breik[6] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
			AV[0] != 0 && AV[1] != 0 && !breik[7] ? (AV[0]--, AV[1]--) : breik[7] = true; //"jos ruutu on vielä laudalla, iteroi sitä eteenpäin/taaksepäin"
		}
	}	
}

void annaRatsunLaillisetSiirrot(vector<Siirto*> * _lista, Ruutu * _alotusRuutu, Asema * _lauta, int _vari)
{
	//check if right color piece
	if (_vari != _lauta->getSiirtoVuoro())
	{

	}
	else
	{
		int R[2] = { _alotusRuutu->getSarake() , _alotusRuutu->getRivi() }; //ratsun koordinaatit

																			//katsotaan, onko (ruutu johon ollaan siirtämässä tyhjä tai siinä on vastustajan nappula) ja sijaitseeko se pelialueella:
																			//ylös 2, oik. 1
		if (((_lauta->lauta[R[0] + 1][R[1] + 2] == NULL) || _lauta->lauta[R[0] + 1][R[1] + 2]->getVari() != _vari) && R[0] < 7 && R[1] < 6) {
			_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] + 1, R[1] + 2)));
		}
		//alas 2, oik. 1
		if (((_lauta->lauta[R[0] + 1][R[1] - 2] == NULL) || _lauta->lauta[R[0] + 1][R[1] - 2]->getVari() != _vari) && R[0] < 7 && R[1] > 1) {
			_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] + 1, R[1] - 2)));
		}
		if (R[0] != 0 && R[1] != 0) 
		{ //indeksointi-ongelmia, raaka ja ruma ratkaisu. Muuten kusee, kun ollaan laudan vasemmassa reunassa(R[0] = 0). emt, johtunee taulukon indeksien menemisestä negatiivisiksi.
						 //aiheuttaa kaatumisen GetVari:a kutsuttaessa. Jostain syystä vain X-akselilla. wtf

						 //siirto "ylös 2 ja vasemmalle 1":
			if (((_lauta->lauta[R[0] - 1][R[1] + 2] == NULL) || _lauta->lauta[R[0] - 1][R[1] + 2]->getVari() != _vari) && R[0] > 0 && R[1] < 6) {
				_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] - 1, R[1] + 2)));
			}
			//alas 2, vas. 1
			if (((_lauta->lauta[R[0] - 1][R[1] - 2] == NULL) || _lauta->lauta[R[0] - 1][R[1] - 2]->getVari() != _vari) && R[0] > 0 && R[1] > 1) {
				_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] - 1, R[1] - 2)));
			}

			if (R[0] > 1) {
				//ylös 1, vas. 2
				if (((_lauta->lauta[R[0] - 2][R[1] + 1] == NULL) || _lauta->lauta[R[0] - 2][R[1] + 1]->getVari() != _vari) && R[0] > 1 && R[1] < 7) {
					_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] - 2, R[1] + 1)));
				}
				//alas 1, vas. 2
				if (((_lauta->lauta[R[0] - 2][R[1] - 1] == NULL) || _lauta->lauta[R[0] - 2][R[1] - 1]->getVari() != _vari) && R[0] > 1 && R[1] > 0) {
					_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] - 2, R[1] - 1)));
				}
			}
			if (R[0] < 6)
			{
				//alas 1, oik.2
				if (((_lauta->lauta[R[0] + 2][R[1] - 1] == NULL) || _lauta->lauta[R[0] + 2][R[1] - 1]->getVari() != _vari) && R[0] < 6 && R[1] > 0)
				{
					_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] + 2, R[1] - 1)));
				}
				//ylös 1, oik.2
				if (((_lauta->lauta[R[0] + 2][R[1] + 1] == NULL) || _lauta->lauta[R[0] + 2][R[1] + 1]->getVari() != _vari) && R[0] < 6 && R[1] < 7)
				{
					_lista->push_back(new Siirto(*_alotusRuutu, Ruutu(R[0] + 2, R[1] + 1)));
				}
			}
		}
	}
}

void annaLinnoituksenLaillisetSiirrot(Siirto * siirto)
{
//check if right color piece
	//tornitukset, ei valmis, ekan ehdon voi korvata monella paremmalla
	//lyhyt, valkoinen
	if (lauta_s->getSiirtoVuoro() == 1
		&& !lauta_s->getOnkoValkeaKuningasLiikkunut()
		&& !lauta_s->getOnkoValkeaKTliikkunut() //katsotaan, onko kuningas valkoinen, onko se liikkunut, onko sen puoleinen torni liikkunut
		&& lauta_s->lauta[5][0] == NULL
		&& lauta_s->lauta[6][0] == NULL
		//&& !onkoRuutuUhattu())									      //ovatko ruudut välissä tyhjiä ja liikkuuko kuningas uhatun ruudun yli (!!!placeholderi tässä!!!)
		)
	{
		lailliset_siirrot_s->push_back(new Siirto(true, false));
	}
	//pitkä, valkoinen
	if (lauta_s->getSiirtoVuoro() == 1
		&& !lauta_s->getOnkoValkeaKuningasLiikkunut()
		&& !lauta_s->getOnkoValkeaDTliikkunut() //katsotaan, onko kuningas valkoinen, onko se liikkunut, onko Q:n puoleinen torni liikkunut
		&& lauta_s->lauta[1][0] == NULL
		&& lauta_s->lauta[2][0] == NULL
		&& lauta_s->lauta[3][0] == NULL
		//&& !onkoRuutuUhattu()) 		  //ovatko ruudut välissä tyhjiä ja liikkuuko kuningas uhatun ruudun yli (!!!placeholderi tässä!!!)
		)
	{
		lailliset_siirrot_s->push_back(new Siirto(false, true));
	}
	//lyhyt, musta
	if (lauta_s->getSiirtoVuoro() == -1
		&& !lauta_s->getOnkoMustaKuningasLiikkunut()
		&& !lauta_s->getOnkoMustaKTliikkunut() //katsotaan, onko kuningas valkoinen, onko se liikkunut, onko sen puoleinen torni liikkunut
		&& lauta_s->lauta[5][7] == NULL
		&& lauta_s->lauta[6][7] == NULL
		//&& !onkoRuutuUhattu())									      //ovatko ruudut välissä tyhjiä ja liikkuuko kuningas uhatun ruudun yli (!!!placeholderi tässä!!!)
		)
	{
		lailliset_siirrot_s->push_back(new Siirto(true, false));
	}
	//pitkä, musta
	if (lauta_s->getSiirtoVuoro() == -1
		&& !lauta_s->getOnkoMustaKuningasLiikkunut()
		&& !lauta_s->getOnkoMustaDTliikkunut() //katsotaan, onko kuningas valkoinen, onko se liikkunut, onko Q:n puoleinen torni liikkunut
		&& lauta_s->lauta[1][7] == NULL
		&& lauta_s->lauta[2][7] == NULL
		&& lauta_s->lauta[3][7] == NULL
		//&& !onkoRuutuUhattu()) 		  //ovatko ruudut välissä tyhjiä ja liikkuuko kuningas uhatun ruudun yli (!!!placeholderi tässä!!!)
		)
	{
		lailliset_siirrot_s->push_back(new Siirto(false, true));
	}
}

