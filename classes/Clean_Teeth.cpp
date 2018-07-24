#include "Clean_Teeth.h"



Clean_Teeth::Clean_Teeth(D_GeneralPracticioner doctor, string Name, Data date, double value)
	: Procedures(Name, date, value), Doctor(doctor)
{ /* empty */ }


Clean_Teeth::~Clean_Teeth()
{ /* empty */ }


void Clean_Teeth::printInformation()
{
	Procedures::printInformation();

	cout << "\n Doctor's name: " << Doctor.getName()
		<< "\n Doctor's specialty: " << Doctor.getEspecialty()
		<< "\n Doctor's professional number: " << Doctor.getProfessionalNumber() << endl;

}