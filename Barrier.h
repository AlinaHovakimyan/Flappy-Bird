#ifndef BARRIER_H
#define BARRIER_H

#include "GameObject.h"
class Barrier :
	public GameObject
{
public:
	Barrier(Point origin, Size size);
	PhysicBody physic_body();
};

#endif