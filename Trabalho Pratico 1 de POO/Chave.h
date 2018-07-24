// Preprocessor directive, to avoid multiple calls to the same file

#ifndef CHAVE_H
#define CHAVE_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include "segmentoEletrico.h"

using namespace std;// Using the std namespace to simplify the function calls

class Chave : public segmentoEletrico
{
public:
	Chave();
	Chave(bool On_OFF);
	~Chave();
	bool getEstado();
	void setEstado(bool on_off);
private:
	bool On_OFF;
};

#endif
