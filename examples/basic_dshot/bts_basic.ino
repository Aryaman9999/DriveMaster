/*!
 * @file bts_basic.ino
 */
#include <SerialIo.h>
#include "DriveMaster.h"
#include "BTS7960MotorController.h"

#define RX_PIN 16

sbus_channels_t channelData;
sbus receiver(&Serial1, RX_PIN);
BTS7960MotorController motor(5, 6, 7, 8); // User-defined pins

void setup() { 
  receiver.begin();
  motor.begin();
  Serial.begin(9600);
}

void loop() {
  receiver.processIncoming();
  receiver.getChannel(&channelData);

  motor.controlMotor(&channelData);

  // Optionally print the channel data for debugging
  Serial.print("Channel 1: ");
  Serial.print(channelData.channel1);
  Serial.print(" Channel 2: ");
  Serial.print(channelData.channel2);
  Serial.print(" Channel 3: ");
  Serial.print(channelData.channel3);
  Serial.print(" Channel 4: ");
  Serial.println(channelData.channel4);
}
