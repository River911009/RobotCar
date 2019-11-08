/**
 * Name:    Robot Car Library
 * Author:  River
 * Date:    03 May 2019
 * Description:
 *   HC-SR04 Created by Martin Sosic, June 11, 2016.
 */

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "RobotCar.h"

Car::Car(void){
}

uint8_t Car::initial(uint8_t type, uint8_t Lmotor, uint8_t Rmotor){
  _MotorConnectType = type;
  _LeftMotor_Speed  = Lmotor;
  _RightMotor_Speed = Rmotor;
  
  pinMode(_LeftMotor_Minus, OUTPUT);
  pinMode(_LeftMotor_Plus, OUTPUT);
  pinMode(_RightMotor_Minus, OUTPUT);
  pinMode(_RightMotor_Plus, OUTPUT);

  pinMode(_LeftIR, INPUT_PULLUP);
  pinMode(_MiddleIR, INPUT_PULLUP);
  pinMode(_RightIR, INPUT_PULLUP);

  pinMode(_HCSR04_Trig, OUTPUT);
  pinMode(_HCSR04_Echo, INPUT);

  pinMode(_Joystick_Button, INPUT);
  return(0);
}

// Motors motion
uint8_t Car::moveStop(void){
  setMotor(0, 0);
  return(0);
}

uint8_t Car::moveForward(int8_t _speed){
  setMotor(_speed, _speed);
  return(0);
}

uint8_t Car::moveBack(int8_t _speed){
  setMotor(-_speed, -_speed);
  return(0);
}

uint8_t Car::moveClockWiseRotate(int8_t _speed){
  setMotor(_speed, -_speed);
  return(0);
}

uint8_t Car::moveCounterClockWiseRotate(int8_t _speed){
  setMotor(-_speed, _speed);
  return(0);
}

uint8_t Car::moveForwardLeft(int8_t _speed){
  setMotor(0, _speed);
  return(0);
}

uint8_t Car::moveForwardRight(int8_t _speed){
  setMotor(_speed, 0);
  return(0);
}

uint8_t Car::moveBackLeft(int8_t _speed){
  setMotor(0, -_speed);
  return(0);
}

uint8_t Car::moveBackRight(int8_t _speed){
  setMotor(-_speed, 0);
  return(0);
}

uint8_t Car::setMotor(int8_t _Left, int8_t _Right){
  if(_Left > 0){
    analogWrite((_MotorConnectType & 0b10)?_LeftMotor_Plus:_LeftMotor_Minus, map(_Left, 0, 100, 0, _LeftMotor_Speed));
  }
  else if(_Left < 0){
    analogWrite((_MotorConnectType & 0b10)?_LeftMotor_Minus:_LeftMotor_Plus, map(_Left, 0, -100, 0, _LeftMotor_Speed));
  }
  else{
    digitalWrite(_LeftMotor_Minus, LOW);
    digitalWrite(_LeftMotor_Plus, LOW);
  }

  if(_Right > 0){
    analogWrite((_MotorConnectType & 0b01)?_RightMotor_Plus:_RightMotor_Minus, map(_Right, 0, 100, 0, _RightMotor_Speed));
  }
  else if(_Right < 0){
    analogWrite((_MotorConnectType & 0b01)?_RightMotor_Minus:_RightMotor_Plus, map(_Right, 0, -100, 0, _RightMotor_Speed));
  }
  else{
    digitalWrite(_RightMotor_Minus, LOW);
    digitalWrite(_RightMotor_Plus, LOW);
  }
  return(0);
}

// IR sensors
uint8_t Car::getInfrared(uint8_t *_Left, uint8_t *_Middle, uint8_t *_Right){
  *_Left   = digitalRead(_LeftIR);
  *_Middle = digitalRead(_MiddleIR);
  *_Right  = digitalRead(_RightIR);
  return(0);
}

double Car::getUltrasonic(void){
  // Make sure that trigger pin is LOW.
  digitalWrite(_HCSR04_Trig, LOW);
  delayMicroseconds(2);
  // Hold trigger for 10 microseconds, which is signal for sensor to measure distance.
  digitalWrite(_HCSR04_Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_HCSR04_Trig, LOW);
  // Measure the length of echo signal, which is equal to the time needed for sound to go there and back.
  unsigned long durationMicroSec = pulseIn(_HCSR04_Echo, HIGH);
  double distanceCm = durationMicroSec / 2.0 * 0.0343;
  if(distanceCm == 0 || distanceCm > 400){
    return -1.0 ;
  }
  else{
    return distanceCm;
  }
}

uint8_t Car::getJoystick(int8_t *_Xaxis, int8_t *_Yaxis, int8_t *_Button){
  *_Xaxis  = map(analogRead(_Joystick_Xaxis), 0, 1023, -100, 100);
  *_Yaxis  = map(analogRead(_Joystick_Yaxis), 0, 1023, -100, 100);
  *_Button = digitalRead(_Joystick_Button);
  return(0);
}

