#include <iostream>
#include<iomanip>
#include "Employee.h"

Employee::Employee(string Name, int Id, int age, char gender, int regNumber)
	: Person(Name, Id, age, gender)
{
	setRegisterNumber(regNumber);
}

Employee::~Employee()
{ /* empty */ }


void Employee::setRegisterNumber(int regNumber)
{
	RegisterNumber = (regNumber > 0) ? regNumber : 0;
}


int Employee::getRegisterNumber()
{
	return RegisterNumber;
}


void Employee::printInformation()
{
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Name:                |  " << Person::getName() << setw(64-Person::getName().size()) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| ID:                  |  " << Person::getID() << setw(63) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Age:                 |  " << Person::getAge() << setw(62) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Gender:              |  " << Person::getGender() << setw(63) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
	cout << "| Registration Number: |  " << getRegisterNumber() << setw(60) << setfill(' ') << "|" << endl;
	cout << "|----------------------------------------------------------------------------------------|" << endl;
}