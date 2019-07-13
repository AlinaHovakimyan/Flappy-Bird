#ifndef PHYSICBODY_H
#define PHYSICBODY_H
#include "Definitions.h"
class PhysicBody
{
public:
	PhysicBody(int id, Point origin, Size size, Vector velocity, int m);
	PhysicBody(const PhysicBody &);
	 ~PhysicBody();
	 void set_m(int m);
	 void set_velocity(Vector v);
	 void set_size(Size size);
	 void set_origin(Point point);
	 int get_m() const;
	 Vector get_velocity() const;
	 Size get_size() const;
	 Point get_origin() const;
	 Rect get_frame() const;
	 void move();
	 void applyAcceleration(Vector acceleration);

protected:
	int m_id;
	int m_m;
	Rect m_frame;
	Vector m_velocity;
};

#endif 
