#ifndef ODENTIST_H
#define ODENTIST_H

#include "Dentist.h"

class D_Orthodontist : public Dentist
{
public:
	D_Orthodontist(string Name, int Id, int age, char gender, int regNumber, int professionalNumber, string especialty, int yearsOfexperience);
	~D_Orthodontist();
	
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