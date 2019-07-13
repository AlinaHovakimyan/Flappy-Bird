#include "GameObject.h"

int GameObject::autoIncrement = 0;

GameObject::GameObject()
{
	m_id = ++autoIncrement;
}


GameObject::~GameObject()
{

}

void GameObject::update_state(const PhysicBody & rectPhysicBody)
{
	update_origin(rectPhysicBody.get_origin());
	update_size(rectPhysicBody.get_size());
}

void GameObject::update_size(Size size)
{
	m_size = size;
}

void GameObject::update_origin(Point origin)
{
	m_origin = origin;
}

Size GameObject::get_size() const
{
	return m_size;
}

Point GameObject::get_origin() const
{
	return m_origin;
}

int GameObject::get_id() const
{
	return m_id;
}

