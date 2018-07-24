// Budget.h
// INTERFACE DA CLASSE BUDGET.H
#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

#include "Data.h"
#include "Procedures.h"

class Budget
{
public:
	Budget(Data date, Procedures *proc, int size, bool value = 0, double amount = 0);
	~Budget();
	
	void setValue(double amount) { Amount = amount; }
	void setPaid(bool value) { paid = value; }

	bool getPaid() { return paid; }
	double getValue() { return Amount; }

	double getTotalValue();
	void getProcedures();

	void printBudgetInformation();

private:
	Data PaymentDate;
	bool paid = 0;
	list<Procedures> procedures;
	double Amount;
};



#endif // BUDGET_H
