#ifndef NAPPULA_H
#define NAPPULA_H

#include <string>
using namespace std;


class Nappula {

private:
	wstring nimi;
	wstring unicode;
	int vari;

public:

	Nappula(wstring, wstring, int);
	Nappula() {};

	void setNimi(wstring);

	wstring getNimi();

	void setUnicode(wstring);

	const wstring getUnicode();

	void setVari(int);

	const int getVari();

	~Nappula()
	{
		//delete this;
	}

};
#endif