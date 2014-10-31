#include <PumpkinRobot.h>
#include <math.h>

PumpkinRobot::PumpkinRobot(int left_wing, int right_wing) :
	min_wing_speed_(0),
	max_wing_speed_(100),
	LED_per_eye_(8),
	num_eyes_(2),
	left_wing_speed_(0),
	right_wing_speed_(0),
	left_wing_angle_(90),
	right_wing_angle_(90),
	robot_state_(SLEEPING)
{
	// The servo pin for the wings are configurable through the left wing
	// and right wing angle parameters
	left_wing_.attach(left_wing);
	right_wing_.attach(right_wing);
	
  left_eye_on_ = right_eye_on_ = true;	
  left_blink_freq_ = right_blink_freq_ = 0.0;
  
}

void PumpkinRobot::reconfigureRobot()
{
  // Set everything to run smoothly
    
}

void PumpkinRobot::step()
{
  // Get potentiometer value: [0,1023]
  left_wing_speed_ = right_wing_speed_ = map(scarometer_, 0, 100, 0, 1024);
  left_blink_freq_ = right_blink_freq_ = map(scarometer_, min_blink_freq_, max_blink_freq_, 0, 1024);
}
