#include "Object.hpp"

namespace AI
{
namespace engine
{

const Float ZERO = 0.01f;
const Float DRAG = 8.0f;
const Float FORCE = 3.0f;
const Float BACK_FORCE = 2.0f;

bool Object::accelerate()
{
	if (tspeed > ZERO)
	{
		Float acc = FORCE/tspeed;
		if (acc < ZERO) acc = 0;
	}
	else
	{
		acc = FORCE;
	}

	tspeed += acc;
}

bool Object::decelerate()
{
	if (tspeed < -ZERO)
	{
		Float acc = BACK_FORCE/-tspeed;
		if (acc < ZERO) acc = 0;
	}
	else
	{
		acc = DRAG;
	}

	tspeed -= acc;
}

void Object::setThrust(bool left, bool right)
{
	
}

void Object::updatePosition()
{
}

} // engine
} // AI
