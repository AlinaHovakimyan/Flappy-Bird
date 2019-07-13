#ifndef Cit_H
#define Cit_H

#include "GameObject.h"
class Cit :
	public GameObject
{
public:
	virtual void update_state(const Rect frame);
	virtual void update_size(Size size);
	virtual void update_origin(Point origin);

};

#endif