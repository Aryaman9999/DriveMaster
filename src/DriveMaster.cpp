/**
 * @file DriveMaster.cpp
 * @brief Source file for the DriveMaster class.
 */

#include "DriveMaster.h"

DriveMaster::DriveMaster(int pin) : _pin(pin) {}

DriveMaster::~DriveMaster() {}

void DriveMaster::begin() {}

void DriveMaster::write(uint16_t value, bool telemetry) {}

void DriveMaster::sendCommand(uint16_t value) {}

void DriveMaster::sendValue(uint16_t value) {}
