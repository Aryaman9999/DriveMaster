/**
 * @file BTS7960MotorController.h
 * @brief Header file for the BTS7960MotorController class.
 */

#pragma once
#ifndef BTS7960MOTORCONTROLLER_H
#define BTS7960MOTORCONTROLLER_H

#include <Arduino.h>
#include <SerialIo.h>
#include "DriveMaster.h"

/**
 * @brief Derived class for BTS7960 motor control.
 */
class BTS7960MotorController : public DriveMaster {
public:
  /**
   * @brief Construct a new BTS7960MotorController object with the specified pins.
   * @param RPWM Pin number for RPWM.
   * @param LPWM Pin number for LPWM.
   * @param L_EN Pin number for L_EN.
   * @param R_EN Pin number for R_EN.
   */
  BTS7960MotorController(int RPWM, int LPWM, int L_EN, int R_EN);
  /**
   * @brief Initialize the motor control.
   */
  void begin() override;
  /**
   * @brief Control the motor using SBUS channel data.
   * @param channelData Pointer to the SBUS channel data.
   */
  void controlMotor(sbus_channels_t* channelData);

private:
  int _RPWM; /**< Pin number for RPWM. */
  int _LPWM; /**< Pin number for LPWM. */
  int _L_EN; /**< Pin number for L_EN. */
  int _R_EN; /**< Pin number for R_EN. */
};

#endif // BTS7960MOTORCONTROLLER_H
