#define movementDetection  HIGH

#define LEDon              HIGH
#define LEDoff             LOW

#define enabled            true
#define disabled           false


const byte heartbeatLED  = 13;
const byte  led          = 8;
const byte  pir          = 2;

bool autoOffFlag         = disabled;

byte lastPIRstate        = !movementDetection;
byte val;
byte state               = 0;
byte LEDstate            = LEDoff;


// Timing 
const unsigned long timeoutDuration = 15 * 60 * 1000ul; //15 minutes

unsigned long heartbeatMillis;
unsigned long switchMillis;
unsigned long autoMillis;

void setup()
{
  pinMode(heartbeatLED, OUTPUT);

  //turn the light OFF
  digitalWrite(led, LEDoff);
  pinMode(led, OUTPUT);

  pinMode(pir, INPUT);

} 

void loop()
{

  if (millis() - heartbeatMillis >= 500)
  {
    heartbeatMillis = millis();

    digitalWrite(heartbeatLED, !digitalRead(heartbeatLED));
  }

  if (millis() - switchMillis >= 50)
  {
    switchMillis = millis();

    checkSwitches();
  }

  if (autoOffFlag == enabled && millis() - autoMillis >= timeoutDuration)
  {
    autoOffFlag = disabled;

    LEDstate = LEDoff;

    digitalWrite(led, LEDoff);
  }

} 
void checkSwitches()
{

  byte state = digitalRead(pir);

  if (lastPIRstate != state)
  {
    lastPIRstate = state;

    if (state == movementDetection)
    {
      LEDstate = !LEDstate;

      digitalWrite(led, LEDstate);

      if (LEDstate == LEDon)
      {
        autoOffFlag = enabled;

        autoMillis = millis();
      }

      else
      {

        autoOffFlag = disabled;
      }

    }

  } 


}
