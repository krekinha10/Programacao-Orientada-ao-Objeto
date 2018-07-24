#include<iostream>
#include<iomanip>
#include "D_Orthodontist.h"


D_Orthodontist::D_Orthodontist(string Name, int Id, int age, char gender, int regNumber, int professionalNumber, string especialty, int yearsOfexperience)
	: Dentist(Name, Id, age, gender, regNumber, professionalNumber)
{
	setEspecialty(especialty);
	setYearsOfExperience(yearsOfexperience);
}


D_Orthodontist::~D_Orthodontist()
{ /* empty */ }

void D_Orthodontist::printInformation()
{
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "|----------------------        Professional Information         -------------------------|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	Dentist::printInformation();
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Especialty:            |  " << getEspecialty() << setw(62 - getEspecialty().size()) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Years of experience:   |  " << getYearsOfExperience() << setw(60) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "\n\n" << endl;

}

