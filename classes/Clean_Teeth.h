#ifndef CLEANTEETH_H
#define CLEANTEETH_H

#include "D_GeneralPracticioner.h"
#include "Procedures.h"

class Clean_Teeth : public Procedures
{
public:
	Clean_Teeth(D_GeneralPracticioner doctor, string Name, Data date, double value);
	~Clean_Teeth();

	void printInformation();

private:
	D_GeneralPracticioner Doctor;
};

#endif