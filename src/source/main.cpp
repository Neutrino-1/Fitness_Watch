#include "../include/main.h"
time_t prevDisplay = 0; // when the digital clock was displayed
void setup()
{
  // put your setup code here, to run once:
  pinMode(navButton, INPUT_PULLUP);
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
      Serial.println(digitalClockValue());
      // WiFi.mode(WIFI_OFF);
    }
  }

  calculateGraphics();
  calculateMotion();
  // put your main code here, to run repeatedly:
}

ICACHE_RAM_ATTR void ISR()
{
  pressed = true;
}