#include "../include/sensor.h"
#define UpperThreshold 620
#define LowerThreshold 520

int16_t x = 0;
int16_t b = 5;
int16_t xLast = 0;
int16_t yLast = 0;
int LastTime = 0;
int ThisTime;
bool BPMTiming = false;
bool BeatComplete = false;
int BPM = 0;
// bool downHit = false;

void calculateGraphics()
{
    if (x > 127)
    {
        clearDisplay();
        x = 0;
        xLast = x;
    }

    ThisTime = millis();
    int value = analogRead(0);
    int b = 60 - (value / 12);
    setGraphingValue(x, b, xLast, yLast, BPM);
    yLast = b;
    xLast = x;

    if (value > UpperThreshold)
    {
        if (BeatComplete)
        {
            BPM = ThisTime - LastTime;
            BPM = int(60 / (float(BPM) / 1000));
            //Serial.println(BPM);
            BPMTiming = false;
            BeatComplete = false;
        }
        if (BPMTiming == false)
        {
            LastTime = millis();
            BPMTiming = true;
        }
    }
    if ((value < LowerThreshold) & (BPMTiming))
    {
        BeatComplete = true;
    }
    x++;
    delay(25);
}