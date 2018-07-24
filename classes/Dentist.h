#ifndef DENTIST_H
#define DENTIST_H

#include "Employee.h"
#include <string>
using namespace std;

class Dentist : public Employee
{
public:
	Dentist(string Name, int Id, int age, char gender, int regNumber, int professionalNumber);
	~Dentist();

	void setProfessionalNumber(int number) { ProfessionalNumber = number; }
	int getProfessionalNumber() { return ProfessionalNumber; }

	void printInformation();

private:
	int ProfessionalNumber;
};

#endif