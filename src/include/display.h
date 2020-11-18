#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"

void initDispaly();

void initUI();

void clearDisplay();

int16_t remainingTimeBudget();

void setDisplayTime(String currentTime);

void uiControl();

void drawGraph();

void setGraphingValue(int16_t x, int16_t y, int16_t lx, int16_t ly, int bpm);

void text(String str, int x, int y, OLEDDISPLAY_TEXT_ALIGNMENT textAlignment, const uint8_t *fontData);

void text(String str, int x, int y, OLEDDISPLAY_TEXT_ALIGNMENT textAlignment);

void text(String str, int x, int y, const uint8_t *fontData);

void text(String str, int x, int y);