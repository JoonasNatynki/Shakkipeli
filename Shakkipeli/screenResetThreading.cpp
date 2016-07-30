#include "screenResetThreading.h"
#include "myNames.h"
using namespace myNames;

extern Kayttoliittyma * os_s;

void reset_Text_Thread( void * number)
{
	Sleep(4000);
	info_text = DEFAULT_TEXT; //RESET TEXT
	os_s->piirraLauta(info_text); //DRAW NEW FRAME
	_endthread();
}