#ifndef FLAPPYCIT_H
#define FLAPPYCIT_H

#include "Cit.h"
class FlappyCit :
	public Cit
{
public:
	FlappyCit();
	// Gives each object's physic body, which is the analogy of the model in PhysicWorld
	PhysicBody physic_body();
};

#endif
