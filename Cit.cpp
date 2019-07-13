#include "Cit.h"

void Cit::update_state(const Rect frame)
{
	update_origin(frame.origin);
	update_size(frame.size);
}

void Cit::update_size(Size size)
{
	m_size = size;
}

void Cit::update_origin(Point origin)
{
	m_origin = origin;
}



