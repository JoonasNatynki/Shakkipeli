#include "nappula.h"
using namespace std;

//CTOR
Nappula::Nappula(const wstring _nimi, const wstring _unicode, const int _vari)
{
	nimi = _nimi;
	unicode = _unicode;
	vari = _vari;
}

void Nappula::setNimi(const wstring _nimi)
{
	nimi = _nimi;
}

wstring Nappula::getNimi()
{
	return nimi;
}

void Nappula::setUnicode(const wstring _unicode)
{
	unicode = _unicode;
}

const wstring Nappula::getUnicode()
{
	return unicode;
}

void Nappula::setVari(int x)
{
	vari = x;
}

//	WARNING SETVARI()!
//	VARI = CONST INT	,
//	CANT BE SET OUTSIDE CTOR	,
//	IF SET, GETVARI() = ERR.
//	
//void Nappula::setVari(int _vari)
//	{
//		vari = _vari;
//	}
//	


const int Nappula::getVari()
{
	return vari;
}
