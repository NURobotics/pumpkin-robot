#include <Servo.h>
#include <PumpkinRobot.h>

PumpkinRobot *Bertram;

void setup()
{
  Bertram = new PumpkinRobot;
}

void loop()
{
  // Set the scarometer speed using the potentiometer
  Bertram->step();
}
