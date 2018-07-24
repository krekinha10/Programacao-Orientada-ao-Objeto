#ifndef GENERAL_H
#define GENERAL_H

#include "Dentist.h"
#include <string>
using namespace std;

class D_GeneralPracticioner : public Dentist
{
public:
	D_GeneralPracticioner(string Name, int Id, int age, char gender, int regNumber, int professionalNumber, string especialty, int yearsOfexperience);
	~D_GeneralPracticioner();
	
	// set functions
	void setEspecialty(string espec) { Especialty = espec; }
	void setYearsOfExperience(int years) { YearsOfExperience = years; }

	// get functions
	string getEspecialty() { return Especialty; }
	int getYearsOfExperience() { return YearsOfExperience; }

	void printInformation();

private:
	string Especialty; // especialidade
	int YearsOfExperience;
};

#endif
