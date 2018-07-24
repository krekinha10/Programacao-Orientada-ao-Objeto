// Preprocessor directive, to avoid multiple calls to the same file
#ifndef FONTE_H
#define FONTE_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include "segmentoEletrico.h"

using namespace std;// Using the std namespace to simplify the function calls

class Fonte : public segmentoEletrico
{
public:
	Fonte();
	~Fonte();
	double getTensão();
	void setTensão(double);
	double getCorrente();
	void setCorrente(double);
private:
    double Tensão;
    double Corrente;
}

#endif
