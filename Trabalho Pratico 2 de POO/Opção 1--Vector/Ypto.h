// Header file for class Ypto

#include <iostream> 
#include <vector>

#ifndef YPTO_H //Preprocessor directives for the class Ypto
#define YPTO_H

using namespace std; 

class Ypto // Class definition 
{
public:
	Ypto() // Constructor for the class
	{};
	~Ypto() // Destructor
	{};
	void setInt(int num); // Member function to set values to the data members.
	int getInt(int i); // Function to get a data member from the private data.
	void DisplayVectorContents(); // Function to display all  the elements of the data menber vector.
	int Sum()const; // Function to sum all the elements from the data member vector.
	int Product() const; // Function to mutiply all the elements from the data member vector.

private:
	vector<int> Dados; // Data member for the class. 
}; // Class end.

#endif
