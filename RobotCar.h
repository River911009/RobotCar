/**
 * Name:    Robot Car Library
 * Author:  River
 * Date:    03 May 2019
 * Description: peripherals are 
 *   1. Left/Right motors
 *   2. Left/Middle/Right IR sensors
 *   3. Microphone
 *   4. Servo motor
 *   5. Ultrasonic sensor (HC-SR04 Created by Martin Sosic, June 11, 2016.)
 *   6. Joystick
 */

#ifndef __ROBOTCAR_H__
#define __ROBOTCAR_H__

#include <stdint.h>
#include "hardware.h"

/**
 * class
 */

class Car{
public:
  Car(void);
  uint8_t initial(uint8_t type, uint8_t Lmotor, uint8_t Rmotor);
  // Motors motion
  uint8_t moveStop(void);
  uint8_t moveForward(int8_t _speed);
  uint8_t moveBack(int8_t _speed);
  uint8_t moveClockWiseRotate(int8_t _speed);
  uint8_t moveCounterClockWiseRotate(int8_t _speed);
  uint8_t moveForwardLeft(int8_t _speed);
  uint8_t moveForwardRight(int8_t _speed);
  uint8_t moveBackLeft(int8_t _speed);
  uint8_t moveBackRight(int8_t _speed);
  uint8_t setMotor(int8_t _left, int8_t _right);
  // Sensors detection
  uint8_t getInfrared(uint8_t *_Left, uint8_t *_Middle, uint8_t *_Right);
  double  getUltrasonic(void);
  uint8_t getJoystick(int8_t *_Xaxis, int8_t *_Yaxis, int8_t *_Button);
  
private:
/**
 * Enviroment variables
 * 
 * There are four types of connection called 00, 01, 10, 11.
 *   Change MSB if Left motor was running wrong direct.
 *   Change LSB if Right motor was running wrong direct.
 * The top speed of two motors are not complete same,
 *   Change two numbers from 0 to 255, let them running on same speed.
 */
  uint8_t _MotorConnectType  = 0b00;
  uint8_t _LeftMotor_Speed  = 255;
  uint8_t _RightMotor_Speed = 255;
};

#endif
