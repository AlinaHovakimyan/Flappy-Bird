#include "FlappyCit.h"

FlappyCit::FlappyCit()
{
	//initial state
	m_size.height = FlappyInitialHeight;
	m_size.width = FlappyInitialWidth;
	m_origin.x = (BoardWidth - FlappyInitialWidth) / 2;
	m_origin.y = (BoardHeight - FlappyInitialHeight) / 2;
}

// Gives each object's physic body, which is the analogy of the model in PhysicWorld
PhysicBody FlappyCit::physic_body()
{
	int m = FlappyInitialM;
	Vector velocity = { NoVelocity, NoVelocity };
	PhysicBody physicBody(this->m_id, m_origin, m_size, velocity, m); //the id of current object will be the same as it's physic body's id
	return physicBody;
}
