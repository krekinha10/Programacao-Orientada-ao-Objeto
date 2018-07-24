#ifndef CLINIC_H
#define CLINIC_H

#include <vector>
#include <string>
#include "Patient.h"
#include "Employee.h"
using namespace std;

class Clinic
{
public:
	Clinic(string Name);
	~Clinic();
	void set_Clinic_Name(string);
	string get_Clinic_Name();
	void add_People(Patient*);
	void add_Employee(Employee*);
	void Send_Message(string);
	void Delete_People();
	void Delete_Employee();
	void print_Clients();
	void print_Employees();
private:
	vector<Patient*> Clients;
	vector<Employee*> Employees;
	string Clinic_Name;
};
#endif
