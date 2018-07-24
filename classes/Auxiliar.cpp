#include "Auxiliar.h"
#include <iostream>
#include<iomanip>


Auxiliar::Auxiliar(string Name, int Id, int age, char gender, int regNumber, string type, string qualification)
	: Employee(Name, Id, age, gender, regNumber)
{
	setType(type);
	setQualification(qualification);
}


Auxiliar::~Auxiliar()
{ /* empty */ }


void Auxiliar::printInformation()
{
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "|----------------------        Professional Information         -------------------------|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	Employee::printInformation();
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Position :     |  " <<getType()<< setw(62) <<setfill(' ')<< "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Qualification: |  " <<getQualificcation()<< setw(61) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "\n\n" << endl;
}