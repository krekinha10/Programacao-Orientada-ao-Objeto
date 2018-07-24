#include "Budget.h"


Budget::Budget(Data date, Procedures * proc, int size, bool value, double amount)
	: PaymentDate(date), Amount(amount)
{
	procedures.assign(proc, proc + size);
}


Budget::~Budget()
{ /* empty */ }


double Budget::getTotalValue()
{
	
	for (list<Procedures>::iterator it = procedures.begin(); it != procedures.end(); it++)
	{
		Amount += it->getPrice();
	}

	return Amount;
}

void Budget::getProcedures()
{
	int counter = 0;
	int Frequency[6];
	string Name_Procedures[6] = { "Clean_Teeth","Deploy_Braces","Remove_Braces","Repair_Braces","Restore_Teeth","Remove_Teeth" };

	for (int i = 0; i < 6; i++)
	{
		for (list<Procedures>::iterator it = procedures.begin(); it != procedures.end(); it++)
		{
			if (it->getName() == Name_Procedures[i])
			{
				counter++;
			}

		}
		Frequency[i] = counter;
		counter = 0;
	}

	cout << setw(7) << "Times" << setw(13) << "Procedure" << endl;
	for (int j = 0; j < 6; j++)
	{
		cout << setw(5) << Frequency[j] << "x" << setw(16) << Name_Procedures[j] << endl;
	}

}

void Budget::printBudgetInformation()
{
	cout << "\n Payment date: ";
	
	if (getPaid() == 1)
		cout << PaymentDate;
	else
		cout << "Not yet paid";
	
	cout << "\n Total amount : " << getValue()
		<< "\n Procedures: ";

	cout << setw(8) << "\n Name: ";
	for (list<Procedures>::iterator it = procedures.begin(); it != procedures.end(); it++)
		cout << it->getName() << setw(25);

	cout << setw(8) << "\n Date: ";
	for (list<Procedures>::iterator it = procedures.begin(); it != procedures.end(); it++)
		cout << it->getDate() << "    ";

	cout << setw(8) << "\n Price: ";
	for (list<Procedures>::iterator it = procedures.begin(); it != procedures.end(); it++)
		cout << it->getPrice() << setw(25);

	cout << "\n\n";
}
