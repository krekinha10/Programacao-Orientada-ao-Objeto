// Preprocessor directive, to avoid multiple calls to the same file
#ifndef FONTECA_H
#define FONTECA_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include<cmath>
#include "Fonte.h"

using namespace std;// Using the std namespace to simplify the function calls

class FonteCA : public Fonte
{
public:
	FonteCA();
	FonteCA(double Freq, double Amp);
	~FonteCA();
	double getFrequencia();
	void setFrequencia(double Freq);
	double getAmp();
	void setAmp(double Amp);
	double TensaoRMS();
private:
    double Frequencia;
	double Amplitude;
};

#endif
