#include "../include/mpu.h"

Adafruit_MPU6050 mpu;

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

Events calculateMotion()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    // Serial.print("Acceleration X: ");
    // Serial.print(a.acceleration.x);
    // Serial.print(", Y: ");
    // Serial.print(a.acceleration.y);
    // Serial.print(", Z: ");
    // Serial.print(a.acceleration.z);
    // Serial.println(" m/s^2");

    // Serial.print("Rotation X: ");
    // Serial.print(g.gyro.x);
    // Serial.print(", Y: ");
    // Serial.print(g.gyro.y);
    // Serial.print(", Z: ");
    // Serial.print(g.gyro.z);
    // Serial.println(" rad/s");

    // Serial.print("Temperature: ");
    // Serial.print(temp.temperature);
    // Serial.println(" degC");

    // Serial.println("");

    if (a.acceleration.z > 12)
    {
        Serial.println("UP MOTION");
        return UP_MOTION;
    }
    else if (a.acceleration.z < 7)
    {
        Serial.println("DOWN MOTION");
        return DOWN_MOTION;
    }

    delay(500);
    return LEFT_MOTION;
}