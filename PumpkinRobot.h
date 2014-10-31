#ifndef PUMPKIN_ROBOT_H
#define PUMPKIN_ROBOT_H

#include <Arduino.h>
#include <Servo.h>

enum RobotState {
	CREEPY,
	SCARY,
	TAUNTING,
	SLEEPING
};

class PumpkinRobot {
public:
	Servo left_wing_;
	Servo right_wing_;
	
	int left_wing_angle_;
	int right_wing_angle_;
	
	int left_wing_speed_;
	int right_wing_speed_;
  
  int scarometer_;
	
  bool left_eye_on_, right_eye_on_;
	double left_blink_freq_, right_blink_freq_;
  
	RobotState robot_state_;
	
	PumpkinRobot(int left_wing=3, int right_wing=5);
  void step();

private:
	int min_wing_speed_;
	int max_wing_speed_;
  
  int max_blink_freq_;
  int min_blink_freq_;
	
	int LED_per_eye_;
	int num_eyes_;
};

#endif
