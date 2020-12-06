# Fitness_Watch

A fitness watch based on esp12E with arudino frame work.

Current Features inlcudes:
* Auto display turn on and turn off
* Motion detection
* Heart Rate sensor
* NTP time sync
* Haptic feedback
* SMTP email functionality

![Fitness watch final build](https://github.com/Neutrino-1/Fitness_Watch/blob/master/circuit/fitness%20watch.gif)

### Getting Started

Clone this repo and open the folder with **VScode** along with **Platform**.io extension
all the other necessary files will open along with it.

Change the external library to your arduino library path in **platformio.ini** file

```
lib_extra_dirs = C:\Users\*USER NAME*\Documents\Arduino\libraries
```

### Library Prerequisites

* [ESP-Core](https://github.com/esp8266/Arduino) - by Ivan Grokhotkov
* [TimeLib](https://github.com/PaulStoffregen/Time) - by PaulStoffregen
* [EmailSender](https://github.com/xreef/EMailSender) - xreef
* [Adafruit 6050](https://github.com/adafruit/Adafruit_MPU6050) - adafruit
* [Wifi Manager](https://github.com/tzapu/WiFiManager) - tzapu
* [OLED](https://github.com/ThingPulse/esp8266-oled-ssd1306) - ThingPulse

### Installing

Open the Arduino IDE and follow the below steps:
```
Sketch -> include library -> ManageLibrary -> *Search for the above libraries*
```
Or
follow the instructions on respective library repository.

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Neutrino-1/Fitness_Watch/blob/master/LICENSE) file for details
