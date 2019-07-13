#ifndef PHYSICWORLD_H
#define PHYSICWORLD_H

#include "PhysicsEngine.h"
#include "PhysicWorldDelegate.h"
#include <vector>

class PhysicWorld {
public:
	PhysicWorld( PhysicBody cit, int gravityAcceleration = 0);
	void set_gravity_acceleration(int gravityAcceleration);
	void replace_cit(PhysicBody cit);
	void add_barrier(PhysicBody barrier);
	void set_cit_velocity(Vector velocity);
	void set_delegate(PhysicWorldDelegate * delegate);
	void fps_action();
 private:
	int m_gravityAcceleration;
	PhysicBody m_cit;
	std::vector<PhysicBody> m_barriers;
	PhysicWorldDelegate * m_delegate;
	PhysicsEngine m_physics;
	bool cit_is_out();
	void collision_action();
};

#endif
