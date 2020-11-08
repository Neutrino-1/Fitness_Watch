#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"

void initDispaly();

void initUI();

void clearDisplay();

int16_t remainingTimeBudget();

void setDisplayTime(String currentTime);

void uiControl();

void text(String str, int x, int y, OLEDDISPLAY_TEXT_ALIGNMENT textAlignment, const uint8_t *fontData);

void text(String str, int x, int y, OLEDDISPLAY_TEXT_ALIGNMENT textAlignment);

void text(String str, int x, int y, const uint8_t *fontData);

void text(String str, int x, int y);