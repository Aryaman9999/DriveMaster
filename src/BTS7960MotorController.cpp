/**
 * @file BTS7960MotorController.cpp
 * @brief Source file for the BTS7960MotorController class.
 */

#include "BTS7960MotorController.h"

BTS7960MotorController::BTS7960MotorController(int RPWM, int LPWM, int L_EN, int R_EN) 
  : DriveMaster(-1), _RPWM(RPWM), _LPWM(LPWM), _L_EN(L_EN), _R_EN(R_EN) {}

void BTS7960MotorController::begin() {
  pinMode(_RPWM, OUTPUT);
  pinMode(_LPWM, OUTPUT);
  pinMode(_L_EN, OUTPUT);
  pinMode(_R_EN, OUTPUT);

  digitalWrite(_RPWM, LOW);
  digitalWrite(_LPWM, LOW);
  digitalWrite(_L_EN, LOW);
  digitalWrite(_R_EN, LOW);
}

void BTS7960MotorController::controlMotor(sbus_channels_t* channelData) {
  int throttleValue = map(channelData->channel3, 172, 1811, 0, 1024);
  int yawValue = map(channelData->channel4, 172, 1811, 0, 1024);

  // Enable motor driver
  digitalWrite(_L_EN, HIGH);
  digitalWrite(_R_EN, HIGH);

  if (yawValue > 512) { // Forward direction
    if (yawValue > 768) { // Right
      analogWrite(_RPWM, throttleValue / 2); // Slow down right wheel
      analogWrite(_LPWM, throttleValue);
    } else { // Forward
      analogWrite(_RPWM, throttleValue);
      analogWrite(_LPWM, throttleValue);
    }
  } else { // Reverse direction
    if (yawValue < 256) { // Left
      analogWrite(_LPWM, throttleValue / 2); // Slow down left wheel
      analogWrite(_RPWM, throttleValue);
    } else { // Reverse
      analogWrite(_LPWM, throttleValue);
      analogWrite(_RPWM, throttleValue);
    }
  }

  delay(20); // Small delay for smoother operation
}
