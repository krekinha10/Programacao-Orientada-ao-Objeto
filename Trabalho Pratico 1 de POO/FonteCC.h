// Preprocessor directive, to avoid multiple calls to the same file

#ifndef FONTECC_H
#define FONTECC_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include<cmath>
#include "Fonte.h"

using namespace std;// Using the std namespace to simplify the function calls

class FonteCC : public Fonte
{
public:
	FonteCC();
	~FonteCC();

private:

};

#endif
