//Class ArraySize definition 

#include <stdexcept> //stdexcept header file contains runtime_error
using namespace std;

#ifndef ARRAYSIZE_H
#define ARRAYSIZE_H

//The class SizeOfData should be thrown by functions upon detecting 
//overflow or searching in a position that don't exist in the Data.

class  ArraySize : public runtime_error
{
	public: 
		// Constructor specifies default error message
		ArraySize() 
			: runtime_error("Attemp to acess a position that doesn't pertence to the Data"){}

}; //End of the class


#endif