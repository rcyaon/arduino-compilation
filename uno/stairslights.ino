const int trigPin = 9;  // Trigger pin of the ultrasonic sensor
const int echoPin = 10;  // Echo pin of the ultrasonic sensor
const int numLeds = 5;   // Number of LEDs in the linear motion
const int ledPinStart = 2;  // Starting digital pin for the LEDs

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPinStart + i, OUTPUT);
  }
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the ultrasonic pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance based on the speed of sound
  distance = duration * 0.034 / 2;

  // Map the distance to the number of LEDs
  int numLedsToLight = map(distance, 5, 100, 0, numLeds);
  numLedsToLight = constrain(numLedsToLight, 0, numLeds);

  // Turn on LEDs based on the calculated distance
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPinStart + i, i < numLedsToLight ? HIGH : LOW);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | LEDs: ");
  Serial.println(numLedsToLight);

  delay(100);  // Adjust the delay based on your requirements
}
