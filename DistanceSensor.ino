#include <Wire.h>
#include "Adafruit_VL6180X.h"

Adafruit_VL6180X vl6180;
int startTime;

void setup() {
    Serial.begin(115200);

    // Initialize VL6180X (ToF sensor)
    if (!vl6180.begin()) {
        Serial.println("VL6180X not found!");
        while (1);
    }
    Serial.println("VL6180X Ready!");

    startTime = millis();
}

void loop() {
    // Read distance from VL6180X
    int distance = vl6180.readRange();
    double time = (millis() - startTime) / 1000.0;
    Serial.print(time);
    Serial.print(",");
    Serial.println(distance);

    delay(1000);
}