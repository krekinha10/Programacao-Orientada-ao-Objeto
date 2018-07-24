#include "Clinic.h"
#include "Patient.h"
#include "Employee.h"
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;



Clinic::Clinic(string Name)
{
	set_Clinic_Name(Name);
}


Clinic::~Clinic()
{
}

void Clinic::add_People(Patient* Persona)
{
	Clients.push_back(Persona);
}
void Clinic::Send_Message(string sms)
{
	for (vector<Patient*>::iterator iter = Clients.begin(); iter != Clients.end(); iter++)
	{
		(*iter)->setMessage(sms);
	}

}
void Clinic::Delete_People()
{
	for (vector<Patient*>::iterator iter = Clients.begin(); iter != Clients.end(); iter++)
	{
		(*iter)-> ~Patient();
	}

	Clients.erase(Clients.begin(), Clients.end());
}

void Clinic::set_Clinic_Name(string Name)
{
	Clinic_Name = Name;
}

string Clinic::get_Clinic_Name()
{
	return Clinic_Name;
}

void Clinic :: add_Employee(Employee* Workers)
{
	Employees.push_back(Workers);
}

void Clinic::Delete_Employee()
{
	for (vector<Employee*>::iterator iter = Employees.begin(); iter != Employees.end(); iter++)
	{
		(*iter)-> ~Employee();
	}

	Employees.erase(Employees.begin(), Employees.end());
}

 void Clinic::print_Clients()
{
	 if(Clients.empty())
	 {
		 cout << "this vector is empty" << endl;
		 return;
	 }
	 for (vector<Patient*>::iterator iter = Clients.begin(); iter != Clients.end(); iter++)
	 {
		 cout << (*iter)->getName() << endl;
		 cout << (*iter)->getMessage() << endl;
	 }
}

 void Clinic::print_Employees()
 {
	 for (vector<Employee*>::iterator iter = Employees.begin(); iter != Employees.end(); iter++)
	 {
		 cout << (*iter)->getName() << endl;
	 }
 }