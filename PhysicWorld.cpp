#include "PhysicWorld.h"
#include "Renderer.h"

PhysicWorld::PhysicWorld(PhysicBody cit, int gravityAcceleration)
	: m_gravityAcceleration(gravityAcceleration),
	 m_cit(cit),
	 m_physics(gravityAcceleration)
{
}

void PhysicWorld::set_gravity_acceleration(int gravityAcceleration) {
	m_gravityAcceleration = gravityAcceleration;
	m_physics.set_gravity_acceleration(gravityAcceleration);
}

void PhysicWorld::replace_cit(PhysicBody cit)
{
	m_cit = cit;
}

void PhysicWorld::add_barrier(PhysicBody barrier)
{
	m_barriers.push_back(barrier);
}

void PhysicWorld::set_cit_velocity(Vector velocity)
{
	m_cit.set_velocity(velocity);
}

void PhysicWorld::set_delegate(PhysicWorldDelegate * delegate)
{
	m_delegate = delegate;
}

void PhysicWorld::fps_action()
{
	m_physics.update(m_cit);
	m_delegate->update_cit(m_cit.get_frame());
	int position = 0;
	if (cit_is_out()) {
		collision_action();
	}
	while (position < m_barriers.size()) {
		PhysicBody current = m_barriers[position];
		if (current.get_origin().x > m_cit.get_origin().x + m_cit.get_size().width) {
			break;
		}
		if (m_physics.check_collision(current, m_cit)) {
			collision_action();
			break;
		}
		position++;
	}
	if (m_barriers.front().get_origin().x < m_cit.get_origin().x - BoardWidth / 2 - BarrierInitialWidth) 
	{
		m_barriers.erase(m_barriers.begin());
		m_barriers.erase(m_barriers.begin());
		m_delegate->remove_barriers_front();
	}
}

void PhysicWorld::collision_action() {
	m_cit.set_velocity( {m_cit.get_velocity().v_y, 0});
	m_delegate->fatal_collision();
}

bool PhysicWorld::cit_is_out() {
	if (m_cit.get_origin().y + m_cit.get_size().height < 0) return true;
	if (m_cit.get_origin().y - m_cit.get_size().height > BoardHeight) return true;
	return false; 
}
