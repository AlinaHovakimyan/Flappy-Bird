#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "PhysicBody.h"

class PhysicsEngine {
public:
	PhysicsEngine(int gravityAcceleration);
	void update(PhysicBody &);
	bool check_collision(const PhysicBody &, const PhysicBody &);	
	void set_gravity_acceleration(int gravityAcceleration);
private:
	int m_gravityAcceleration;
};

#endif
