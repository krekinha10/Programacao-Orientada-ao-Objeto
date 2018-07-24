// Preprocessor directive, to avoid multiple calls to the same file

#ifndef CIRCUITOELETRICO_H
#define CIRCUITOELETRICO_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "FonteCA.h"
#include "FonteCC.h"
#include "FontedeCorrente.h"
#include "Chave.h"
#include "Indutor.h"
#include "Capacitor.h"
#include "Resistor.h"




using namespace std;// Using the std namespace to simplify the function calls

class circuitoEletrico
{
public:
    circuitoEletrico();
    ~circuitoEletrico();
    void calcular Circuito();
private:
    vector <Chave>;
    vector <Resistor>;
    vector <Indutor>;
    vector <Capacitor>;
    vector <FonteCA>;
    vector <FonteCC>;
    vector <FontedeCorrente>;

};

#endif
