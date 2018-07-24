// Header file for class Ypto

#include <iostream>
#include <vector>


#ifndef YPTO_H //Preprocessor directives for the class Ypto
#define YPTO_H

using namespace std;

class Ypto // Class definition 
{
	public:
		Ypto(int size); // Constructor for the class with a parameter to initialize the array.
		~Ypto(); // Destructor
		void setInt(); // Member function to set values to the data members.
		int getInt(int i);// Function to get a data member from the private data.
		void DisplayVectorContents();// Function to display all  the elements of the data menber vector.
		int Sum()const;  // Function to sum all the elements from the data member vector.
		int Product() const; // Function to mutiply all the elements from the data member vector.
	
    private:
        int capacity; // Data member to define the size of the array
        int *Dados; // Data member that represents a pointer to the array.
}; // Class end.

#endif
