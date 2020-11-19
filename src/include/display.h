#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"

void initDispaly();

void initUI();

void clearDisplay();

int16_t remainingTimeBudget();

void setDisplayTime(String currentTime);

void uiControl();

void changeFrame();

void drawGraph();

void onDispaly();

void turnOffDisplay();

void setGraphingValue(int16_t x, int16_t y, int16_t lx, int16_t ly, int bpm);