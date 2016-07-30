#ifndef history
#define history

#include "siirto.h"
#include "nappula.h"
using namespace std;

class History
{

public:

	Siirto * siirto_h = new Siirto;
	Nappula * nabula_h = new Nappula;

	History(Siirto siirto)
	{
		*siirto_h = siirto;
		nabula_h = NULL;
	};
};

#endif