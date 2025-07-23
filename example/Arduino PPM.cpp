#include <Arduino.h>
#include <FlySky.h>

#define PPM_PIN 2  // PPM signal input pin
#define NUM_CHANNELS 6  // Number of channels

FLYSKY FSReceiver(PPM_PIN, NUM_CHANNELS);

void setup() {
  Serial.begin(9600);
  FSReceiver.attachInterrupt();
  Serial.println("PPM Receiver Initialized");
}

void loop() {
  for(uint8_t i = 0; i < NUM_CHANNELS; i++) {
        Serial.print("Channel ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.println(FSReceiver.getPpmValue(i + 1));
    }
    delay(1000); // Print values every second
}
