//Class SizeOfData definition, class defined to handling exceptions.

#include <stdexcept> //stdexcept header file contains runtime_error
using namespace std;

#ifndef SIZEOFDATA_H
#define SIZEOFDATA_H

//The class SizeOfData should be thrown by functions upon detecting 
//overflow or searching in a position that don't exist in the Data.

class SizeOfData : public runtime_error
{
	public: 
	// Constructor specifies default error message
		SizeOfData()
			: runtime_error("Attemp to acess a position that doesn't belong to the Data"){}

}; //End of the class

#endif