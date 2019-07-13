#include "PhysicBody.h"



PhysicBody::PhysicBody(int id, Point origin, Size size, Vector velocity, int m)
{
	m_id = id;
	m_frame.origin = origin;
	m_frame.size = size;
	m_velocity = velocity;
	m_m = m;
}

PhysicBody::PhysicBody(const PhysicBody &initial)
{
	m_id = initial.m_id;
	m_frame.origin = initial.m_frame.origin;
	m_frame.size = initial.m_frame.size;
	m_velocity = initial.m_velocity;
	m_m = initial.m_m;
}

PhysicBody::~PhysicBody()
{
}

void PhysicBody::set_m(int m)
{
	m_m = m;
}

void PhysicBody::set_velocity(Vector v)
{
	m_velocity = v;
}

void PhysicBody::set_size(Size size)
{
	m_frame.size = size;
}

void PhysicBody::set_origin(Point origin)
{
	m_frame.origin = origin;
}

int PhysicBody::get_m() const
{
	return m_m;
}

Vector PhysicBody::get_velocity() const
{
	return m_velocity;
}

Size PhysicBody::get_size() const
{
	return m_frame.size;
}

Point PhysicBody::get_origin() const
{
	return m_frame.origin;
}

Rect PhysicBody::get_frame() const
{
	return m_frame;
}


void PhysicBody::move()
{
	if (m_m <= 0)
		return;
	Point newOrigin = { get_origin().x + get_velocity().v_x, get_origin().y + get_velocity().v_y };
	set_origin(newOrigin);
}

void PhysicBody::applyAcceleration(Vector acceleration)
{
	m_velocity = m_velocity + acceleration;
}

