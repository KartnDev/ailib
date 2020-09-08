#include "pch.h"
class ValueException : public exception
{
public:
	explicit ValueException(const char* msg) : exception(msg)
	{

	}
};

