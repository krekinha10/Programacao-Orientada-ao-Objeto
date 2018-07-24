//Main program to test the class

#include <iostream>
#include <vector>
#include "Ypto.h"
#include "ArraySize.h"

using namespace std;

// The main changes in the user programs are:
// *As we are using a array to store data for the data member 
// the values of the array positions do not need to be filled in the 
// Constructor, it can be filled in operation time.
// *The program now doesn't have a limitation of number of elements to
// be stored in the class data member.




int main()
{
	int Data = 0;
	int Position = 0;
	int Value = 0;
	int NumberOfData = 0;

	//Setting the size of the data array
	cout << "Enter the number of data that you want to store in a vector: " << endl;
	cin >> NumberOfData;

	// Create a class, define its size an add a few items
	Ypto x1(NumberOfData);
	x1.setInt();
	

	// Display the vector contents so far
	x1.DisplayVectorContents();
	cout << '\n';

	//Print the sum of the Vector's data
	cout << "The sum of the data items is: " << x1.Sum() << endl;
	cout << '\n';

	//Print the product of the Vector's data
	cout <<"The product of the data items is: " << x1.Product() << endl;
	cout << '\n';

	// Code to test the exception handling
	cout << "Enter the position that you wanna get from the data: ";
	cin >> Position;

	try
	{
		Value = x1.getInt(Position);
		cout << "The data from the position" << Position << " is " << Value << "." << endl;
	} // End try

	catch (ArraySize &arraySize)
	{
		cout << "Exception occurred: "
			<< arraySize.what() << endl;
	}// End Catch


	return 0;
}
