#ifndef AUXILIAR_H
#define AUXILIAR_H

#include "Employee.h"


class Auxiliar : public Employee
{
public:
	Auxiliar(string Name, int Id, int age, char gender, int regNumber, string type, string qualification);
	~Auxiliar();

	// set functions
	void setType(string type) { Type = type; }
	void setQualification(string qualification) { Qualification = qualification; }

	// get functions
	string getType() { return Type; }
	string getQualificcation() { return Qualification; }

	void printInformation();

private:
	string Type;
	string Qualification;
};

#endif