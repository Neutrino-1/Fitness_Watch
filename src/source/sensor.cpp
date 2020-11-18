#include "../include/sensor.h"
#define UpperThreshold 620
#define LowerThreshold 520

int16_t a = 0;
int16_t b = 5;
int16_t lasta = 0;
int16_t lastb = 0;
int LastTime = 0;
int ThisTime;
bool BPMTiming = false;
bool BeatComplete = false;
int BPM = 0;
// bool downHit = false;

void calculateGraphics()
{
    if (a > 127)
    {
        clearDisplay();
        a = 0;
        lasta = a;
    }

    ThisTime = millis();
    int value = analogRead(0);
    int b = 60 - (value / 12);
    setGraphingValue(a, b, lasta, lastb, BPM);
    lastb = b;
    lasta = a;

    if (value > UpperThreshold)
    {
        if (BeatComplete)
        {
            BPM = ThisTime - LastTime;
            BPM = int(60 / (float(BPM) / 1000));
            Serial.println(BPM);
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
    a++;
    delay(25);
}