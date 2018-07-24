#ifndef INDUTOR_H// Preprocessor directive, to avoid multiple calls to the same file
#define INDUTOR_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include "segmentoEletrico.h"

using namespace std; // Using the std namespace to simplify the function calls

class Indutor : public segmentoEletrico
{
public:
	Indutor();
	Indutor(double Indutancia);
	~Indutor();
    double getIndutancia();
	void setIndutancia(double);
private:
	double Indutancia;
}

#endif
