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
uint8_t _Left, _Middle, _Right;

void setup() {
  // setup your robot car on first argument:
  //   set 0b10 if left wheel turn wrong direction.
  //   set 0b01 if right wheel turn wrong direction.
  //   set 0b11 if both wheels turn wrong direction.
  // setup your robot car wheel top speed limitation:
  robot.initial(0b00, 255, 255);

  // setup serial interface.
  Serial.begin(9600);
}

void loop() {
  // read those ir sensors.
  robot.getInfrared(&_Left, &_Middle, &_Right);

  // show on serial monitor.
  Serial.print("\nLeft:");
  Serial.print(_Left);
  Serial.print("\tMiddle:");
  Serial.print(_Middle);
  Serial.print("\tRight:");
  Serial.print(_Right);
  if(!_Middle) robot.moveForward(100); else robot.moveStop();
  delay(1000);
}

