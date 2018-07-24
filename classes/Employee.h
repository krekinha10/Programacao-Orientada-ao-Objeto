
// Employee.h
// INTERFACE DA CLASSE EMPLOYEE.H

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

class Employee: public Person
{
public:
	Employee(string Name, int Id, int age, char gender, int regNumber);
	~Employee();
	
	void setRegisterNumber(int regNumber);
	int getRegisterNumber();

	void printInformation();

private:
	int RegisterNumber;
};



#endif // EMPLOYEE_H

