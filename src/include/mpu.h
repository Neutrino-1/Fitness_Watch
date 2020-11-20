#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <EMailSender.h>

void setupMPU();
bool calculateMotion();
bool jerkDetection();
bool sendMail(int noOfWarning);