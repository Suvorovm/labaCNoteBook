#pragma once
#include <string>
#include "TypePerson.h"
class IStatus
{
public:

	virtual std::string getTheStatus() = 0;
	virtual TypePerson getThePoint() = 0;
	~IStatus();
	
};

