#include "Deploy_Braces.h"


Deploy_Braces::Deploy_Braces(D_Orthodontist doctor, string Name, Data date, double value)
	: Procedures(Name,date,value), Doctor(doctor)
{ /* empty */ }


Deploy_Braces::~Deploy_Braces()
{ /* empty */ }


void Deploy_Braces::printInformation()
{
	Procedures::printInformation();

	cout << "\n Doctor's name: " << Doctor.getName()
		<< "\n Doctor's specialty: " << Doctor.getEspecialty()
		<< "\n Doctor's professional number: " << Doctor.getProfessionalNumber() << endl;

}