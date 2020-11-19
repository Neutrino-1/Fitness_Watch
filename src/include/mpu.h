#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

enum Events
{
    LEFT_MOTION,
    RIGHT_MOTION,
    UP_MOTION,
    DOWN_MOTION,
    TURN_ON_DIPSLAY
};

void setupMPU();
Events calculateMotion();
bool jerkDetection();