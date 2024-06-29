/**
 * @file DriveMaster.h
 * @brief Header file for the DriveMaster class.
 */

#pragma once
#ifndef DRIVEMASTER_H
#define DRIVEMASTER_H

#include <Arduino.h>

/**
 * @brief Base class for motor control.
 */
class DriveMaster {
public:
  /**
   * @brief Construct a new DriveMaster object with the specified pin.
   * @param pin The pin number for motor control.
   */
  DriveMaster(int pin);
  /**
   * @brief Destroy the DriveMaster object.
   */
  virtual ~DriveMaster();
  /**
   * @brief Initialize the motor control.
   */
  virtual void begin();
  /**
   * @brief Write a command to the motor.
   * @param value The command value to write.
   * @param telemetry Flag indicating telemetry presence.
   */
  virtual void write(uint16_t value, bool telemetry = false);
  /**
   * @brief Send a command to the motor.
   * @param value The command value to send.
   */
  virtual void sendCommand(uint16_t value);
  /**
   * @brief Send a value to the motor.
   * @param value The value to send.
   */
  virtual void sendValue(uint16_t value);

protected:
  int _pin; /**< Pin number for motor control. */
};

#include "dshot.h"

#endif // DRIVEMASTER_H
