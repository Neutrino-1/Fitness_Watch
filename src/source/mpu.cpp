#include "../include/mpu.h"

Adafruit_MPU6050 mpu;
int detectionCounter = 0;
int mpuThresh = 40;

int counterX = 0;
int counterY = 0;
int counterZ = 0;

int numberOfTimes = 0;

unsigned long int timer = 0;

bool guestureStarted = false;

void setupMPU()
{
    Serial.println("find MPU6050 chip");
    if (!mpu.begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        while (1)
        {
            delay(10);
        }
    }
    mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
    mpu.setGyroRange(MPU6050_RANGE_250_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
    delay(100);
}

boolean calculateMotion()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    counterX = a.acceleration.x > 25 ? (counterX + 1) : (counterX + 0);
    counterY = a.acceleration.y > 25 ? (counterY + 1) : (counterY + 0);
    counterZ = a.acceleration.z > 25 ? (counterZ + 1) : (counterZ + 0);

    if (jerkDetection())
    {
        Serial.println("Jerk detected!");
        counterX = 0;
        counterY = 0;
        counterZ = 0;
        return true;
    }

    if (a.gyro.x > 5 && (a.acceleration.y < 3 || a.acceleration.y > -3)) //Detect motion only when Y axis parallel to chest
    {
        guestureStarted = true;
    }
    else if (a.gyro.x < -5)
    {
        if (guestureStarted)
        {
            guestureStarted = false;
            return true;
        }
    }

    return false;
}

bool jerkDetection()
{
    if (millis() - timer > 3000)
    {
        timer = millis();
        counterX = 0;
        counterY = 0;
        counterZ = 0;
    }
    if (counterX > 15)
    {
        Serial.println("X : " + String(counterX));
        return true;
    }
    else if (counterY > 15)
    {
        Serial.println("Y : " + String(counterY));
        return true;
    }
    else if (counterZ > 15)
    {
        Serial.println("Z : " + String(counterZ));
        return true;
    }
    return false;
}