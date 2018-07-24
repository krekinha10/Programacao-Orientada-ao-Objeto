#ifndef PEDIATRICIAN_H
#define PEDIATRICIAN_H

#include "Dentist.h"

class D_Pediatrician : public Dentist
{
public:
	D_Pediatrician(string Name, int Id, int age, char gender, int regNumber, int professionalNumber, string especialty, int yearsOfexperience);
	~D_Pediatrician();
	
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