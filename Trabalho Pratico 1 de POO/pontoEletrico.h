// Preprocessor directive, to avoid multiple calls to the same file

#ifndef PONTOELETRICO_H
#define PONTOELETRICO_H

// Declaration of all libraries necessary to the Class.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;// Using the std namespace to simplify the function calls

class pontoEletrico
{
public:
	pontoEletrico();
	pontoEletrico(int ID, double Voltage);
	~pontoEletrico();
private:
	int Id;
	double voltage;
};

#endif
