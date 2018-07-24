#ifndef DEPLOYBRACES_H
#define DEPLOYBRACES_H

#include "D_Orthodontist.h"
#include "Procedures.h"

class Deploy_Braces : public Procedures
{
public:
	Deploy_Braces(D_Orthodontist doctor, string Name, Data date, double value);
	~Deploy_Braces();

	void printInformation();

private:
	D_Orthodontist Doctor;
};

#endif

