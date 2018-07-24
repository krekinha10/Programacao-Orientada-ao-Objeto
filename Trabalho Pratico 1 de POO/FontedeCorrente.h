// Preprocessor directive, to avoid multiple calls to the same file

#ifndef FONTEDECORRENTE_H
#define FONTEDECORRENTE_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <Fonte.h>

using namespace std;// Using the std namespace to simplify the function calls

class FontedeCorrente : public Fonte
{
public:
        FontedeCorrente();
        ~FontedeCorrente();
private:

};

#endif
