// Preprocessor directive, to avoid multiple calls to the same file

#ifndef SEGMENTOELETRICO_H
#define SEGMENTOELETRICO_H

// Declaration of all libraries necessary to the Class.


#include <iostream>
#include <iomanip>
#include<cmath>
#include "pontoEletrico.h"

using namespace std;// Using the std namespace to simplify the function calls


class segmentoEletrico
{
public:
    segmentoEletrico();
    segmentoEletrico(pontoEletrico p1, pontoEletrico p2, int i);
    ~segmentoEletrico();

private:
    int id;
    pontoEletrico ponto1;
    pontoEletrico ponto2;
};

#endif
