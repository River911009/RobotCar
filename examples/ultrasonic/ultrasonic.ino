/**
 * Name:    ultrasonic
 * Author:  River
 * Date:    29 May 2019
 * Description:
 *   Go forward until detected object.
 */
#include "RobotCar.h"

Car robot;
double distance = 0.0;

void setup() {
  // setup your robot car on first argument:
  //   set 0b10 if left wheel turn wrong direction.
  //   set 0b01 if right wheel turn wrong direction.
  //   set 0b11 if both wheels turn wrong direction.
  // setup your robot car wheel top speed limitation:
  robot.initial(0b00, 255, 255);
  robot.moveStop();
}

void loop() {
  distance = robot.getUltrasonic();
  if(distance < 10){
    robot.moveStop();
  }
  else{
    robot.moveForward(50);
  }
}
