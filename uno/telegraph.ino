const int buttonPin = 2;  // Pin where the button is connected
int buttonState = 0;     // Variable to store the button state
String morseCode = "";   // Variable to store Morse code input

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // Button is pressed, read Morse code input
    morseCode = readMorseCode();
    translateAndPrint(morseCode);
    delay(1000);  // Adjust delay based on your requirements
  }
}

String readMorseCode() {
  String input = "";

  while (true) {
    int buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH) {
      delay(50);  // Debounce delay
      if (buttonState == HIGH) {
        input += ".";
      }
    } else {
      delay(50);  // Debounce delay
      if (buttonState == LOW) {
        input += "-";
      }
    }

    delay(200);  // Adjust delay based on Morse code speed
    buttonState = digitalRead(buttonPin);

    if (buttonState == LOW) {
      // Button released, Morse code input complete
      break;
    }
  }

  return input;
}

void translateAndPrint(String morse) {
  // Morse code to letter mapping (add more as needed)
  if (morse == ".-") {
    Serial.print("A");
  } else if (morse == "-...") {
    Serial.print("B");
  } else if (morse == "-.-.") {
    Serial.print("C");
  } else if (morse == "-..") {
    Serial.print("D");
  } else if (morse == ".") {
    Serial.print("E");
  }
  // Add more Morse code to letter mappings for other letters and numbers

  Serial.println();  // Print a newline after translating
}
