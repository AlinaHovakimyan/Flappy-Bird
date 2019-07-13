#ifndef PHYSICWORLDDELEGATE_H
#define PHYSICWORLDDELEGATE_H

#include "Definitions.h"

class PhysicWorldDelegate {
public:
	virtual void fatal_collision() = 0;
	virtual void update_cit(Rect frame) = 0;
	virtual void remove_barriers_front() = 0;
};

#endif