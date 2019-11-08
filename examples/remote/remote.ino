/**
 * Name:    remote
 * Author:  River
 * Date:    29 May 2019
 * Description:
 *   Remote controlled by joystick.
 */
#include "RobotCar.h"

Car robot;
int8_t x = 0, y = 0, b = 0;

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
  robot.getJoystick(&x, &y, &b);
  if(x > 10){
    robot.moveForward(x);
  }
  else if(x < -10){
    robot.moveBack(x);
  }
  else{
    robot.moveStop();
  }

  if(y > 10){
    robot.moveClockWiseRotate(y);
  }
  else if(y < -10){
    robot.moveCounterClockWiseRotate(y);
  }
  else{
    robot.moveStop();
  }
}

