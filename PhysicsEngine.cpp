#include "PhysicsEngine.h"
#include <iostream>

void PhysicsEngine::update(PhysicBody & object)
{
	object.move();
	object.applyAcceleration( { 0, m_gravityAcceleration } );
}

PhysicsEngine::PhysicsEngine(int gravityAcceleration)
{
	m_gravityAcceleration = gravityAcceleration;
}

bool PhysicsEngine::check_collision(const PhysicBody &first, const PhysicBody &second)
{
	if (first.get_origin().x + first.get_size().width < second.get_origin().x) return false; // "second" is on the far right
	if (second.get_origin().x + second.get_size().width < first.get_origin().x) return false; //"second" is on the far left
	if (first.get_origin().y + first.get_size().height < second.get_origin().y) return false; // "second" is up
	if (second.get_origin().y + second.get_size().height - RenderingOffset < first.get_origin().y) return false; // "second" is down

//std::cout<<"First="<<first.get_origin().x<<" "<<first.get_origin().y<<" "<<first.get_size().width<<"/n";
//std::cout<<"Second="<<second.get_origin().x<<" "<<second.get_origin().y;	
 return true;
}

void PhysicsEngine::set_gravity_acceleration(int gravityAcceleration) {
	m_gravityAcceleration = gravityAcceleration;
}
