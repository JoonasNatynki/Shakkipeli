#include <iostream>
#include "asema.h"
#include "kayttoliittyma.h"
#include "laillisetSiirrot.h"
#include <stdlib.h>
#include "siirto.h"
#include <list>
#include <Windows.h>
#include <process.h> //THREADING FUCK YEAH!!!
#include "myNames.h"
#include <vector>
//#include "evaluonti.h"
#include "history.h"

//GLOBAL SINGLETON DECLARATIONS############################
Asema * lauta_s;										//#
Kayttoliittyma * os_s;									//#
wstring tmp_input_s;									//#
list<Siirto> * lista_s;									//#
Siirto * siirto_s;										//#
vector<History*> * siirto_historia_s;						//#
int nabulan_color; //color of piece						//#
wstring nabulan_Nimi;									//#
//Evaluointi * eval; //evaluonti metodit ja arvot			//#
vector<Siirto*> * lailliset_siirrot_s;					//#
int computer_color;
int nappuloita_syöty;//#
//#########################################################