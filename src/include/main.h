#include <Arduino.h>
#include <Wire.h>
#include "./display.h"
#include "./wifiControl.h"
#include "./mpu.h"
#include "./timeControl.h"
#include "./sensor.h"

#define navButton 0
volatile bool pressed = false;
unsigned long idleTime = 0;
volatile bool displayOnStatus = true;
time_t prevDisplay = 0; // when the digital clock was displayed

ICACHE_RAM_ATTR void ISR();