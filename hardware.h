/**
 * Name:    Robot Car Library
 * Author:  River
 * Date:    03 May 2019
 * Description:
 *   Hardware connections
 */
#ifndef __HARDWARE_H__
#define __HARDWARE_H__

// Wheels(recommand using PWM output pin)
#define _LeftMotor_Minus    5
#define _LeftMotor_Plus     6
#define _RightMotor_Minus   9
#define _RightMotor_Plus    10
// IR sensors(recommand using external interrupt pin)
#define _LeftIR             4
#define _MiddleIR           3
#define _RightIR            2
// SG90 servo motor
#define _SG90               11
// Ultrasonic module
#define _HCSR04_Trig        A0
#define _HCSR04_Echo        A1
// Microphone module
#define _Microphone         A2
// Joysticks(with two analog input X and Y, one digital input B)
#define _Joystick_Xaxis     A3
#define _Joystick_Yaxis     A4
#define _Joystick_Button    A5

#endif

