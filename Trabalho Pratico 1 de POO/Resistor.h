// Preprocessor directive, to avoid multiple calls to the same file
#ifndef RESISTOR_H
#define RESISTOR_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include "segmentoEletrico.h"

using namespace std;// Using the std namespace to simplify the function calls

class Resistor : public segmentoEletrico
{
private:
	double Resistencia;

public:
	Resistor();
	Resistor(double R);
	~Resistor();
	double getResistencia();
	void setResistencia(double);
}

#endif
