

#ifndef OPTION_EXCEPTION
#define OPTION_EXCEPTION
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class OptionException
{
public:
	OptionException() {}

	virtual ~OptionException() {}

	virtual string GetMessage() const = 0;

};


#endif