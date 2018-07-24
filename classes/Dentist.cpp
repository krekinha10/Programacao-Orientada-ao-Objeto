#include<iostream>
#include<iomanip>
#include "Dentist.h"


Dentist::Dentist(string Name, int Id, int age, char gender, int regNumber, int professionalNumber) 
	: Employee(Name, Id, age, gender, regNumber)
{
	setProfessionalNumber(professionalNumber);
}


Dentist::~Dentist()
{ /* empty */ }


void Dentist::printInformation()
{
	Employee::printInformation();
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Registro profissional: |  " << getProfessionalNumber() << setw(58) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;

}