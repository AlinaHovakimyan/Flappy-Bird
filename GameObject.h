#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Definitions.h"
#include "PhysicBody.h"


class GameObject
{
	static int autoIncrement;
public:
	GameObject();
	virtual ~GameObject();
	void update_state(const PhysicBody &rectPhysicBody); 
	void update_size(Size size);
	void update_origin(Point point);
	Size get_size() const;
	Point get_origin() const;
	int get_id() const;
	virtual PhysicBody physic_body() = 0;

protected:
	int m_id;
	Size m_size;
	Point m_origin;	
};




#endif