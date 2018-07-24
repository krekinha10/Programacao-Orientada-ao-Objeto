//Main program to test the class

#include <iostream>
#include <vector>
#include "Ypto.h"
#include "SizeOfData.h"

using namespace std;

// The main changes in the user programs are:
// *As we are using a vector class to create a vector data member 
// the values of the vector positions do not need to be filled in the 
// Constructor, it can be filled in operation time.
// *The program now doesn't have a limitation of number of elements to
// be stored in the class data member.

int main()
{
	int Data = 0;
	int Value = 0;
	int Position = 0;
	int NumberOfData = 0;
	
	// Create our class
	Ypto x1;
	cout << '\n';


	//Defining the amount of data to be stored and setting some values to the data
	cout << "Enter the number of data that you want to store in a vector: " << endl;
	cin >> NumberOfData;

	for ( int i = 0; i < NumberOfData; i++) // Loop to fill the data member vector
	{
		cout << "Enter the data that you want to store in the position "<< i <<" : "<< endl;
		cin >> Data;
		x1.setInt(Data);// Assing the values to the vector.
	} 


	// Display the vector contents so far
	x1.DisplayVectorContents();
	cout << '\n';

	//Print the sum of the Vector's data
	cout << "The sum of the elements is " << x1.Sum() << endl;
	cout << '\n';

	//Print the product of the Vector's data
	cout << "The product of the elements is " << x1.Product() << endl;
	cout << '\n';

	// Code to test the exception handling
	cout << "Enter the position that you wanna get from the data: ";
	cin >> Position;

	try
	{
		Value = x1.getInt(Position);
		cout << "The data from the position" << Position << " is " << Value << "." << endl;
	} // End try

	catch (SizeOfData &sizeOfData)
	{
		cout << "Exception occurred: "
			<< sizeOfData.what() << endl;
	}// End Catch



	return 0;
}
