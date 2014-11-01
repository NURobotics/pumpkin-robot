#include <PumpkinRobot.h>
#include <math.h>

PumpkinRobot::PumpkinRobot() :
	min_wing_speed_(0),
	max_wing_speed_(2),
	min_wing_angle_(45),
	max_wing_angle_(900),
	left_wing_speed_(0.0),
	right_wing_speed_(0.0),
	left_wing_angle_(min_wing_angle_),
	right_wing_angle_(min_wing_angle_),
	robot_state_(SLEEPING)
{
  input_state_ = (int*)malloc(sizeof(int)*COUNT);
  pin_number_ = (int*)malloc(sizeof(int)*COUNT);
  memset(input_state_, 0, sizeof(int)*COUNT);
  
  int direction_ = 0;
  
  // Pin configuration
  pin_number_[LEFT_WING] = 11;
  pin_number_[RIGHT_WING] = 10;
  pin_number_[LEFT_EYE] = 6;
  pin_number_[RIGHT_EYE] = 5;
  pin_number_[SCAROMETER] = 0;
  
  // The servo pin for the wings are configurable through the left wing
  // and right wing angle parameters
  left_wing_.attach(pin_number_[LEFT_WING]);
  right_wing_.attach(pin_number_[RIGHT_WING]);
  
  left_eye_on_ = right_eye_on_ = true;	
  left_blink_freq_ = right_blink_freq_ = 0.0;
}

void PumpkinRobot::reconfigureRobot()
{
  // Set everything to run smoothly
  // Calculate next step of wing
  left_wing_.write(left_wing_angle_);
  right_wing_.write(right_wing_angle_);
  
  analogWrite(pin_number_[LEFT_EYE], 255);
  analogWrite(pin_number_[RIGHT_EYE], 255);
}

void PumpkinRobot::step()
{
  if(direction_ == 0) {
	left_wing_angle_ = min_wing_angle_;
	right_wing_angle_ = 180-min_wing_angle_;
  }
  else {
	left_wing_angle_ = max_wing_angle_;
	right_wing_angle_ = 180-max_wing_angle_;
  }
  direction_ = !direction_;
  
  double SCALE = 2000.0;
  scarometer_ = analogRead(pin_number_[SCAROMETER]);
  left_wing_speed_ = right_wing_speed_ = double(map(scarometer_, 0, 1023, min_wing_speed_*2000, max_wing_speed_*2000)/SCALE);
  left_blink_freq_ = right_blink_freq_ = map(scarometer_, 0, 1023, min_blink_freq_, max_blink_freq_);
  
  reconfigureRobot();
  delay(int(1000.0/left_wing_speed_));
}

PumpkinRobot::~PumpkinRobot()
{
  if(input_state_ != NULL)
    free(input_state_);
  if(pin_number_ != NULL)
    free(pin_number_);
}
