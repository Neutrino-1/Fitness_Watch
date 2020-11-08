#include "../include/main.h"
time_t prevDisplay = 0; // when the digital clock was displayed
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting...");
  startWiFiManager();
  initDispaly();
  delay(100);
  //setupMPU();
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
  if (timeStatus() != timeNotSet)
  {
    if (now() != prevDisplay)
    { //update the display only if time has changed
      prevDisplay = now();
      setDisplayTime(digitalClockValue());
      Serial.println(digitalClockValue());
      WiFi.mode(WIFI_OFF);
    }
  }
  //calculateMotion();
  // put your main code here, to run repeatedly:
}