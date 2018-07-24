// Libraries from C++ Standard program.
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>

//Libraries developed to this Practical Work.
#include "Clinic.h"
#include "P_GeneralClinic.h"
#include "P_Orthodontics.h"
#include "P_Pediatrics.h"
#include "D_GeneralPracticioner.h"
#include "D_Orthodontist.h"
#include "D_Pediatrician.h"
#include "Secretary.h"
#include "Auxiliar.h"
#include "Data.h"
#include "Budget.h"
#include "Deploy_Braces.h"
#include "Remove_Braces.h"
#include "Repair_Braces.h"
#include "Restore_Teeth.h"
#include "Clean_Teeth.h"
#include "Remove_Teeth.h"

using namespace std;

const int SizeProblems1 = 3;
const int SizeProblems2 = 3;
const int SizeProcedures1 = 7;


int main()
{
	string f1 = "dd/mm/aaaa"; // date format

	// Dates
	Data date1(f1, "06/11/2017");
	Data date2(f1, "23/08/1993");
	Data date3(f1, "02/03/2007");
	Data date4(f1, "29-02-2000");
	Data date5(f1, "13/02/1999");
	Data date6(f1, "01/01/2000");

	// Dentists
	D_GeneralPracticioner dentist1("Emerson", 1, 24, 'm', 1234, 1234,"General Practiotioner",10);
	dentist1.printInformation();

	D_Orthodontist dentist2("Rafael", 2, 29, 'm', 2223, 1235, "Orthodontist", 15);
	dentist2.printInformation();

	D_Pediatrician dentist3("Jesimon", 3, 21, 'm', 3333, 1236, "Pediatrician", 25);
	dentist3.printInformation();

	Secretary secretary1("Jaqueline", 4, 80, 'f', 1237, "Secretary", 40);
	secretary1.printInformation();

	Auxiliar auxiliar1("Joseph", 5, 20, 'm', 1238, "Auxiliar", "Assistant");
	auxiliar1.printInformation();


	// Procedures
	Deploy_Braces procedures1(dentist2, "Deploy_Braces", date1, 500.20);
	procedures1.printInformation();

	Remove_Braces  procedures2(dentist2, "Remove_Braces", date2, 400.50);
	procedures2.printInformation();
	
	Repair_Braces  procedures3(dentist2, "Repair_Braces", date3, 200.56);
	procedures3.printInformation();

	Restore_Teeth  procedures4(dentist1, "Restore_Teeth", date4, 600.78);
	procedures4.printInformation();

	Clean_Teeth  procedures5(dentist1, "Clean_Teeth", date5, 250.41);
	procedures5.printInformation();

	Remove_Teeth  procedures6(dentist1, "Remove_Teeth", date6, 150.52);
	procedures6.printInformation();
	
	// Budget
	Procedures procedures[SizeProcedures1] = { procedures1, procedures2, procedures3, procedures4, procedures5, procedures6, procedures1 };
	Budget budget1(date1, procedures, SizeProcedures1, 0);

	// Array of Problems - to be associate with a patient
	string problemas1[SizeProblems1] = { "Angle","Simon","Lischer" };
	string problemas2[SizeProblems2] = { "Cares","Fracture","Peridontit" };
	// Patient
	P_GeneralClinic patient1("Gabriela", 1, 22, 'f', 1, budget1, problemas2, SizeProblems2);
	P_Orthodontics patient2("Marcos", 2, 25, 'm', 2, budget1, 3, problemas1, SizeProblems1);
	P_Pediatrics patient3("Felipe", 2, 25, 'm', 2, budget1, "Special", problemas2, SizeProblems2);


	//_____________________________________________
	// Imprime Patient
	
	// patient 1
	patient1.printInformation();
	
	// patient 2
	patient2.printInformation();

	patient2.addProblem("Fracture");
	patient2.printInformation();

	patient2.removeProblem();
	patient2.printInformation();

	// patient 3
	patient3.printInformation();

	//_____________________________________________

	// Imprime Budget Data
	cout << "\n\n" << budget1.getTotalValue();

	cout << "\n\n";
	budget1.getProcedures();
	cout << "\n\n";

	//budget1.printBudgetInformation();

	//_______________________________________________

	Patient *Persona = NULL;
	Employee *Worker = NULL;
	string Message = "The clinic has a new oportunity for its clients,  70 % off in all orthodontics procedures..... ";
	Patient a[3] = { patient1,patient2,patient3 };


	//Creating a Clinic Object
	Clinic Clinic1("Brazil Dental");

	//Printing the name of the Clinic
	cout << Clinic1.get_Clinic_Name() << endl;

	for (int i = 0; i < 3; i++)
	{
		Persona = new Patient(a[i]);
		Clinic1.add_People(Persona);
	}

	Clinic1.Send_Message(Message);

	Clinic1.print_Clients();

	Clinic1.Delete_People();

	Clinic1.print_Clients();

	
	system("PAUSE");

	return 0;
}