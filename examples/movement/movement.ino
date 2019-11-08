/**
 * Name:    movement
 * Author:  River
 * Date:    03 May 2019
 * Description:
 *   Fully speed go forward for 1 second.
 *   Then, stop for 1 second.
 *   Finally go backward for 1 second and repeat above movements.
 */
#include "RobotCar.h"

Car robot;

void setup() {
  // setup your robot car on first argument:
  //   set 0b10 if left wheel turn wrong direction.
  //   set 0b01 if right wheel turn wrong direction.
  //   set 0b11 if both wheels turn wrong direction.
  // setup your robot car wheel top speed limitation:
  robot.initial(0b00, 255, 255);
}

void loop() {
  // go forward for 1 second.
  robot.moveForward(100);
  delay(1000);

  // stop 1 second.
  robot.moveStop();
  delay(1000);

  // go backward for 1 second.
  robot.moveBack(100);
  delay(1000);

  // stop 1 second.
  robot.moveStop();
  delay(1000);
}

