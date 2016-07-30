#ifndef RUUTU_H
#define RUUTU_H

class Ruutu {
public:
	Ruutu(int, int);
	Ruutu() {};
	int getRivi();
	int getSarake();
private:
	int sarake;
	int rivi;
};

#endif