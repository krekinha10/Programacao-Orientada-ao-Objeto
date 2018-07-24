#include<iostream>
#include<iomanip>
#include "D_GeneralPracticioner.h"



D_GeneralPracticioner::D_GeneralPracticioner(string Name, int Id, int age, char gender, int regNumber, int professionalNumber, string especialty, int yearsOfexperience)
	: Dentist(Name, Id, age, gender, regNumber, professionalNumber)
{
	setEspecialty(especialty);
	setYearsOfExperience(yearsOfexperience);
}


D_GeneralPracticioner::~D_GeneralPracticioner()
{ /* empty */ }


void D_GeneralPracticioner::printInformation()
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