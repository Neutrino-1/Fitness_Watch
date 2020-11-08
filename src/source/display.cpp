#include "../include/display.h"

SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_128_32);
OLEDDisplayUi ui(&display);

uint8_t currentFrame = 0;
String timenow = "00:00:00";

void setDisplayTime(String currentTime)
{
    timenow = currentTime;
}

void clock(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{

    display->setFont(ArialMT_Plain_24);
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->drawString(64 + x, 10 + y, timenow);
}

void pulseRate(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
    // The coordinates define the center of the text
    display->setFont(ArialMT_Plain_16);
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->drawString(64 + x, 0 + y, "Night");
    display->setFont(ArialMT_Plain_10);
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    // display->drawString(0 + x, 54 + y, setTimes[2]);
    display->drawString(5 + x, 22 + y, "1. Trazodone");
    display->drawString(5 + x, 34 + y, "2. Acetaminophen");
}

FrameCallback frames[] = {clock, pulseRate};

// how many frames are there?
int frameCount = 5;

void initDispaly()
{
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 16, "Booting...");
    display.display();
}

void initUI()
{
    ui.setTargetFPS(60);
    ui.disableAutoTransition();
    ui.disableAllIndicators();
    ui.setFrameAnimation(SLIDE_LEFT);
    ui.setFrames(frames, frameCount);
    ui.init();
    display.flipScreenVertically();
}

void clearDisplay()
{
    display.clear();
}

int16_t remainingTimeBudget()
{
    return ui.update();
}

void uiControl()
{
    ui.nextFrame();
    OLEDDisplayUiState *currentState = ui.getUiState();
    currentFrame = currentState->currentFrame; //This variable is inside the library!
}

void changeFrame(uint8_t change)
{
    ui.switchToFrame(change);
}