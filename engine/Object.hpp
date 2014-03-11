#ifndef AI_ENGINE_OBJECT_HPP
#define AI_ENGINE_OBJECT_HPP

#include "utils/vector.hpp"
#include "common/common.hpp"

namespace AI
{
namespace engine
{
class Object {
	public:
		bool accelerate();
		bool decelerate();
		void setThrust(bool left, bool right);

		void updatePosition();

		const FVector& getPos() const { return pos; }
		const FVector& getVelocity() const { return velocity; }
		const FVector& getVelocityBody() const { return velocityBody; }
		const FVector& getTSpeed() const { return tspeed; }
		const FVector& getSSpeed() const { return sspeed; }
	private:
		FVector pos; // position
		FVector velocity; // earth coordinate
		FVector velocityBody; // body coordinate

		Float   tspeed;
		Float   sspeed;
		Float   orientation;

		Float   steerLeft;
		Float   steerRight;
};

} // engine 
} // ai

#endif 
