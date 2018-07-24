// Implementation for the Ypto class

#include <iostream>
#include <vector>
#include "Ypto.h"
#include "SizeOfData.h"

using namespace std;

	
void Ypto::setInt(int num) // Implementation for the setInt function.
{
	Dados.push_back(num); // set elements using push_back function that is a property for the vector class. 
}
	
int Ypto::getInt(int i) // Implementation for the getInt function, function that will be used to test the exception 
{                       // handling.
	//Throw the SizeOfData exception if trying to access a position that doesn't pertence to the data.
	if (i > (int)Dados.size())
	{
		throw SizeOfData(); //Terminate the function.
	}

	return Dados[i]; // if doesn't occur an error the function returns the asked value.
}
	
int Ypto::Sum()const // Function calculate the Sum of the elements from the elements os the data member vector.
{
	int sum = 0; //auxiliary value to calculate the Sum.
	if (Dados.size() == 0) // Conditional analysis, if the vector is empty.
	{
		return 0;
	}
		
	for ( int i = 0 ; i < (int)Dados.size() ; i++) // Loop to calculate the sum.
	{
		sum = sum + Dados[i];
	}
	return sum; // return of the function.
}

void Ypto :: DisplayVectorContents() // Function to display the elements from the data member vector.
{
	if (Dados.size() == NULL) //Conditional analysis, if there is no data stored the message below will be diplayed.
	{
		cout << "There is no data stored" << endl;
	}
	for ( int i = 0; i < (int)Dados.size(); i++) // Loop to display the elements from the vector.
	{
		cout << "Element[" << i << "] = " << Dados[i] << endl;
	}
	cout << endl;
}
	
int Ypto::Product()const //Function to calculate the product of the data member elements
{
	 int product = 1; // Auxiliary to calculate the  product.

	 if (Dados.size() == NULL) // Conditional analysis 
	 {
		 return 0;
	 }
	
	for ( int i = 0; i < (int)Dados.size(); i++) // Loop to calculate the product.
	{
		product = product * Dados[i];
	}
	return product; // return of the function.
}
