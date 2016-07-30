#include "ruutu.h"
using namespace std;

Ruutu::Ruutu(int x, int y)
{
	sarake = x;
	rivi = y;
}

int Ruutu::getRivi()
{
	return rivi;
}

int Ruutu::getSarake()
{
	return sarake;
}