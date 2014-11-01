#ifndef PUMPKIN_ROBOT_H
#define PUMPKIN_ROBOT_H

#include <Arduino.h>
#include <Servo.h>

// Not making use of robot states currently
enum RobotState {
  CREEPY,
  SCARY,
  TAUNTING,
  SLEEPING
};

enum INPUTS {
  LEFT_WING,
  RIGHT_WING,
  LEFT_EYE,
  RIGHT_EYE,
  SCAROMETER,
  COUNT
};

class PumpkinRobot {
private:
  int min_wing_speed_;
  int max_wing_speed_;
  
  int min_wing_angle_;
  int max_wing_angle_;
  
  int max_blink_freq_;
  int min_blink_freq_;
	
public:
  // Attachments
  Servo left_wing_;
  Servo right_wing_;
  
  int direction_;
  
  int *input_state_;
  int *pin_number_;
	
  int left_wing_angle_;
  int right_wing_angle_;
	
  double left_wing_speed_;
  double right_wing_speed_;
  
  int scarometer_;
	
  bool left_eye_on_, right_eye_on_;
  double left_blink_freq_, right_blink_freq_;
  
  RobotState robot_state_;
  
  PumpkinRobot();
  ~PumpkinRobot();
  void step();
  void reconfigureRobot();
};

#endif
