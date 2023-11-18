#include <Adafruit_CircuitPlayground.h>

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
}

void loop() {
  // Read accelerometer values
  float x, y, z;
  CircuitPlayground.motionXAccel(&x);
  CircuitPlayground.motionYAccel(&y);
  CircuitPlayground.motionZAccel(&z);

  // Adjust the sensitivity based on your requirements
  float sensitivity = 10.0;

  // Check if a shake is detected
  if (abs(x) > sensitivity || abs(y) > sensitivity || abs(z) > sensitivity) {
    // Trigger vibration (you may need to adjust the duration)
    CircuitPlayground.startMotor(255);  // 255 is full power
    delay(500);  // Vibration duration
    CircuitPlayground.stopMotor();
  }

  delay(100);  // Adjust the delay based on your requirements
}

