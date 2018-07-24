#ifndef CAPACITOR_H // Preprocessor directive, to avoid multiple calls to the same file
#define CAPACITOR_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include "segmentoEletrico.h"

using namespace std; // Using the std namespace to simplify the function calls

class Capacitor : public segmentoEletrico
{
public:
	Capacitor();
	Capacitor(double capacitancia);
	~Capacitor();
	double getCapacitancia();
	void setCapacitancia(double);
private:
	double Capacitancia;
};

#endif
