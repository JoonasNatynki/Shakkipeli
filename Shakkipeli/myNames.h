#ifndef MYNAMES_H
#define MYNAMES_H

#include "siirto.h"
#include "kayttoliittyma.h"
#include <list>
#include "laillisetSiirrot.h"

namespace myNames 
{
	#define DEFAULT_TEXT L"Give next move. [\"q\" or \"Q\" to quit]."
	//varialbe declarations, no more constantly creating new ones on each frame
	//extern Asema * lauta; //Board, Initialize all pieces etc...
	//extern Kayttoliittyma os; //Interface for drawing the window etc...
	//extern list<Siirto> * lista; //the actual list of legal moves for the moving piece
	//extern Siirto siirto; //we don't make this into pointer, because we are only ever creating one of these and not one on each turn
	//extern LaillisetSiirrot ls; //the legal moves interface for the moving piece
	//extern int nabulan_color; //color of piece
	//extern wstring nabulan_Nimi; //name of piece
	extern wstring info_text; //text we use on the screen on each frame draw
	//extern wstring tmp_input;
	//extern bool input_ready;
	//extern wstring siirto_str;

};

#endif