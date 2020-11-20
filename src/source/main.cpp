#include "../include/main.h"

void setup()
{
  // put your setup code here, to run once:
  pinMode(navButton, INPUT_PULLUP);
  pinMode(14, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(0), ISR, FALLING);
  Serial.begin(115200);
  Serial.println("Starting...");
  startWiFiManager();
  initDispaly();
  delay(100);
  setupMPU();
  while (wifiConnected())
    ;
  startTime();
  initUI();
  idleTime = millis();
}

void loop()
{
  if (remainingTimeBudget() > 0)
  {
  }

  if (pressed)
  {
    changeFrame();
    pressed = false;
  }

  if (timeStatus() != timeNotSet)
  {
    if (now() != prevDisplay)
    { //update the display only if time has changed
      prevDisplay = now();
      setDisplayTime(digitalClockValue());
      //Serial.println(digitalClockValue());
      // WiFi.mode(WIFI_OFF);
    }
  }

  calculateGraphics();
  if (calculateMotion())
  {
    if (!displayOnStatus)
    {
      onDispaly();
      displayOnStatus = true;
    }
    idleTime = millis();
  }
  else if (!calculateMotion() && displayOnStatus && millis() - idleTime > 15000)
  {
    displayOnStatus = false;
    turnOffDisplay();
    idleTime = millis();
  }

  // put your main code here, to run repeatedly:
}

ICACHE_RAM_ATTR void ISR()
{
  if (!displayOnStatus)
  {
    onDispaly();
    displayOnStatus = false;
  }
  else
  {
    pressed = true;
  }
}
