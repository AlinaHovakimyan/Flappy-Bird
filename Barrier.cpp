#include "Barrier.h"

Barrier::Barrier(Point origin, Size size)
{
	m_origin = origin;
	m_size = size;
}

PhysicBody Barrier::physic_body()
{
	int m = BarrierInitialM;
	Vector velocity = { NoVelocity, NoVelocity };
	PhysicBody physicBody(this->m_id, m_origin, m_size, velocity, m); //the id of current object will be the same as it's physic body's id
	return physicBody;
}