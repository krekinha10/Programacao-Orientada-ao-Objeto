//Implementation of the class Ypto

#include <iostream>
#include <vector>
#include "Ypto.h"
#include "ArraySize.h"

using namespace std;

Ypto :: Ypto(int size)// Implementation for the constructor of the class.
{
	capacity = size; // define the size of the array.
	Dados = new int[capacity]; // allocation of memory to create the array with defined size.
}

Ypto::~Ypto() // Implementation of the class destructor.
{
	delete[] Dados; // destruction of data member.
}
	
void Ypto::setInt() // Implementation for the setInt function.
{
	int num= 0; //Auxiliary variable to used to set the data for the array
 	
	cout << "Enter the numbers to fill the array " << endl;// Prompt to ask for values to fill the array
	
	for (int i = 0; i < capacity ; i++) // Loop to assure that the user will be asked to fill only the 
	{                                   // valide positions
		cout << "Enter the number to the position " << i <<  ":" <<endl;
		cin >> num; // Receive the data to fil the array.
		Dados[i] = num; // Assing  the value to the array.
	}
}
	
int Ypto::getInt(int i) // Implementation for the getInt function, function that will be used to test the exception
{                        // handling.

	//Throw the ArraySize exception if trying to access a position that doesn't pertence to the data.
	if (i > capacity)
	{
		throw ArraySize(); //Terminate the function.
	}
	return Dados[i]; // if doesn't occur an error the function returns the asked value.
}
	
int Ypto::Sum()const // Function calculate the Sum of the elements from the elements os the data member vector.
{
	int sum = 0; //auxiliary value to calculate the Sum.
		
	for (int i = 0; i < capacity; i++)// Loop to calculate the sum.
	{
		sum = sum + Dados[i];
	}
	return sum;// return of the function.
}

void Ypto :: DisplayVectorContents()// Function to display the elements from the data member vector.
{
	for ( int i = 0; i < capacity; i++)// Loop to display the elements from the vector.
	{
		cout << "Element[" << i << "] = " << Dados[i] << endl;
	}
	cout << endl;
}
	
int Ypto::Product()const //Function to calculate the product of the data member elements
{
	int product = 1;// Auxiliary to calculate the  product.
	
	for (int i = 0; i < capacity; i++)// Loop to calculate the product.
	{
		product = product * Dados[i];
	}
	return product; // return of the function.
}
