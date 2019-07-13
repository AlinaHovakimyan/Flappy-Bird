#include "StdFlapp.h"

Vector Vector::operator+(const Vector &rv)
{
	return { v_x + rv.v_x, v_y + rv.v_y };
}
