#include "main.h" //ALL THE SINGLETONS ETC
#include "history.h"
#include "evaluonti.h"
#include "Pelipuu.h"
#include "minMax.h"

using namespace myNames; //USING OUROWN NAMESPACE SO THAT ALL FUNCTIONS AND METHODS CAN READ THE SAME SHIT

#define MAX_DEPTH 3

void simulate(Asema laatta)
{

	Asema temp_lauta = laatta;
	double asemanArvo = 0;
	int siirtoNum = 0;

	//SIMULATION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int x = 0; x < lailliset_siirrot_s->size(); x++)
	{
		temp_lauta.paivitaAsema(lailliset_siirrot_s->at(x), true);

		//simulate(temp_lauta);
		



		if (abs(evaluoi(temp_lauta)) > asemanArvo)
		{
			asemanArvo = abs(evaluoi(temp_lauta));
			siirtoNum = x;
		}
		temp_lauta = laatta; //reset temp board
	}



	//*lauta_s = temp_lauta; //change the real board to the best move
	*siirto_s = *lailliset_siirrot_s->at(siirtoNum); //set siirto_s to the best move
}




int get_Next_Move(Kayttoliittyma * os, wstring stringgi)
{
	system("cls"); //CLEAR SCREEN FOR NEW FRAME
	os->piirraLauta(stringgi, tmp_input_s); //DRAW NEW FRAME

	//ASK NEXT MOVE AND PRINT SCREEN. SIIRTO WILL BE REFERENCED TO THE RETURNED SIIRTO#########################################################
	if (lauta_s->getSiirtoVuoro() != computer_color)
	{
		
		lailliset_siirrot_s->clear();
		luoLaillisetSiirrotLista(lailliset_siirrot_s, lauta_s); //here we fill and create the lailliset_siirrot lista
		//huolehdiKuninkaanShakeista(); //siivoaa siirrot mitkä laittaa kuninkaan shakkiin
		siirto_s = os->annaVastustajanSiirto(); //THE MOVE WE ARE GOING TO MAKE, THIS ASKS THE PLAYER FOR INPUT AND WAITS UNTIL IT IS GIVEN
		

		lailliset_siirrot_s->clear();
		luoLaillisetSiirrotLista(lailliset_siirrot_s, lauta_s); //here we fill and create the lailliset_siirrot lista
		//huolehdiKuninkaanShakeista();
		/*
		//simulate(*lauta_s); //find the best siirto for lauta_s and automatically puts siirto_s as that siirto
		Pelipuu puu;
		MinMaxPaluu max;
		if (nappuloita_syöty >= 0 && nappuloita_syöty <=4)
		{
			max = puu.maxi(MAX_DEPTH, *lauta_s);
		}
		if (nappuloita_syöty > 4 && nappuloita_syöty <= 8)
		{
			max = puu.maxi(MAX_DEPTH, *lauta_s);
		}
		if (nappuloita_syöty > 9)
		{
			max = puu.maxi(MAX_DEPTH, *lauta_s);
		}
		*siirto_s = max.parasSiirto;
		*/
		
	}
	else
	{
		lailliset_siirrot_s->clear();
		luoLaillisetSiirrotLista(lailliset_siirrot_s, lauta_s); //here we fill and create the lailliset_siirrot lista
		huolehdiKuninkaanShakeista();

		//simulate(*lauta_s); //find the best siirto for lauta_s and automatically puts siirto_s as that siirto
		Pelipuu puu;
		MinMaxPaluu min;
		if (nappuloita_syöty >= 0 && nappuloita_syöty <= 4)
		{
			min = puu.mini(MAX_DEPTH, *lauta_s);
		}
		if (nappuloita_syöty > 4 && nappuloita_syöty <= 8)
		{
			min = puu.mini(MAX_DEPTH, *lauta_s);
		}
		if (nappuloita_syöty > 9)
		{
			min = puu.mini(MAX_DEPTH, *lauta_s);
		}
		*siirto_s = min.parasSiirto;
	}
	//#########################################################################################################################################7









	

	//THREADING IF THE SCREEN TEXT IS NOT DEFAULT_TEXT!!!!
	//info_text != DEFAULT_TEXT ? _beginthread(reset_Text_Thread, 0, NULL) : 0;  // create the thread


	//END MAIN LOOP AND GAME IF PLAYER ENTERS Q OR q###################
	if ((siirto_s)->getAlkuruutu()->getRivi() == 666)				//#
	{																//#
		return 0;													//#
	}																//#
	//#################################################################

	//if not linnotus, set the piece name
	if (!siirto_s->onkoLyhytLinna() && !siirto_s->onkoPitkaLinna())
	{
		nabulan_Nimi = lauta_s->lauta[(siirto_s)->getAlkuruutu()->getSarake()][(siirto_s)->getAlkuruutu()->getRivi()]->getNimi(); //name of moving piece
		nabulan_color = lauta_s->lauta[(siirto_s)->getAlkuruutu()->getSarake()][(siirto_s)->getAlkuruutu()->getRivi()]->getVari();
	}
	else
	{
		nabulan_color = lauta_s->getSiirtoVuoro() == 1 ? 1 : -1; //if player 0's turn, color is 1, if not then color is -1
	}

	nabulan_Nimi = L"";
	nabulan_color = 0;

	//HANDLE GAME RELATED INPUTS!!!
	if (lauta_s->getSiirtoVuoro() != lauta_s->lauta[siirto_s->getAlkuruutu()->getSarake()][siirto_s->getAlkuruutu()->getRivi()]->getVari())
	{
		//confirm the siirto with text on screen
		os_s->printText(L"WRONG COLOR PIECE!");
		//reset singleton siirto_s#####
		delete siirto_s;			//#
		siirto_s = new Siirto;		//#
									//#############################
	}
	else {

		for (int x = 0; x < lailliset_siirrot_s->size(); x++)
		{
			if ((lailliset_siirrot_s->at(x)->getAlkuruutu()->getSarake() == (siirto_s)->getAlkuruutu()->getSarake()
				&& lailliset_siirrot_s->at(x)->getAlkuruutu()->getRivi() == (siirto_s)->getAlkuruutu()->getRivi()
				&& lailliset_siirrot_s->at(x)->getLoppuruutu()->getRivi() == (siirto_s)->getLoppuruutu()->getRivi()
				&& lailliset_siirrot_s->at(x)->getLoppuruutu()->getSarake() == (siirto_s)->getLoppuruutu()->getSarake())
				|| ((siirto_s->onkoLyhytLinna() || siirto_s->onkoPitkaLinna())))
			{
				siirto_historia_s->push_back(new History(*siirto_s)); //push the siirto into the history
				lauta_s->paivitaAsema((siirto_s), false); //HERE WE MOVE THE PIECES!!!

				os_s->printText(L"Moving piece!"); //confirm the siirto with text on screen
												   //reset singleton siirto_s#####
												   //delete siirto_s;			//#
				siirto_s = new Siirto;		//#
											//#############################

				lauta_s->getSiirtoVuoro() == 1 ? lauta_s->setSiirtoVuoro(-1) : lauta_s->setSiirtoVuoro(1); //here we set the player turn to whomever it belongs to
				break;
			}
			else if (x == lailliset_siirrot_s->size() - 1)
			{
				//confirm the siirto with text on screen
				os_s->printText(L"Illegal move!");
				//reset singleton siirto_s#####
				delete siirto_s;			//#
				siirto_s = new Siirto;		//#
											//#############################
			}
		}
	}

	return 1;
}

int main()
{
	//GLOBAL SINGLETON INITIALIZATIONS!!###################################
	lauta_s = new Asema; //Board, Initialize all pieces etc...			//#
	os_s = new Kayttoliittyma(lauta_s);									//#
	tmp_input_s = L"";													//#
	lista_s = new list<Siirto>;											//#
	siirto_s = new Siirto;												//#
	siirto_historia_s = new vector<History*>;							//#
	//eval = new Evaluointi;												//#
	lailliset_siirrot_s = new vector<Siirto*>;
	nappuloita_syöty = 0;//#
	//#####################################################################


	computer_color = os_s->kysyVastustajanVari();


	
	while (1) //GAME MAIN LOOP!!!!!!
	{


		if (get_Next_Move(os_s, info_text) == 0){return 0;}
		if (siirto_historia_s->size() > 10)
		{
			siirto_historia_s->erase(siirto_historia_s->begin());
		}

	}
	

	return 0; //game ends!!!
}