#include <Arduino.h>
#include <Wire.h>
#include "./display.h"
#include "./wifiControl.h"
#include "./mpu.h"
#include "./timeControl.h"
#include "./sensor.h"

#define navButton 0

volatile bool pressed = false;

ICACHE_RAM_ATTR void ISR();