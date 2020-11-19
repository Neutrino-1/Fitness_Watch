#include "../include/display.h"

SSD1306Wire display(0x3c, SDA, SCL, GEOMETRY_128_32);
OLEDDisplayUi ui(&display);

uint8_t currentFrame = 0;
String timenow = "00:00:00";

int16_t x_axis = 0;
int16_t y_axis = 0;
int16_t last_x_axis = 0;
int16_t last_y_axis = 0;
int analogValue = 0;

int displayBPM = 0;

void setDisplayTime(String currentTime)
{
    timenow = currentTime;
}

void setGraphingValue(int16_t x, int16_t y, int16_t lx, int16_t ly, int bpm)
{
    x_axis = x;
    y_axis = y;
    last_x_axis = lx;
    last_y_axis = ly;
    displayBPM = bpm;
}

void clock(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{

    display->setFont(ArialMT_Plain_24);
    display->setTextAlignment(TEXT_ALIGN_CENTER);
    display->drawString(64 + x, 10 + y, timenow);
}

void pulseRate(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y)
{
}

void drawGraph()
{
    // The coordinates define the center of the text

    display.drawLine(last_x_axis, last_y_axis, x_axis, y_axis);
    if (x_axis > 127)
    {
        display.end();
    }
    display.setColor(BLACK);
    display.fillRect(27, 14, 75, 18);
    display.setColor(WHITE);
    display.setFont(ArialMT_Plain_16);
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 16, "BMP : " + String(displayBPM));
    display.display();
}

FrameCallback frames[] = {clock, pulseRate};

// how many frames are there?
int frameCount = 2;

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
    if (currentFrame != 1)
    {
        return ui.update();
    }
    else
    {
        drawGraph();
        return -1;
    }
}

void uiControl()
{
    ui.nextFrame();
    OLEDDisplayUiState *currentState = ui.getUiState();
    currentFrame = currentState->currentFrame; //This variable is inside the library!
    Serial.println("current Frame : " + String(currentFrame));
}

void turnOffDisplay()
{
    display.displayOff();
}

void onDispaly()
{
    display.displayOn();
}

void changeFrame()
{
    clearDisplay();
    ui.switchToFrame(!currentFrame);
    OLEDDisplayUiState *currentState = ui.getUiState();
    currentFrame = currentState->currentFrame; //This variable is inside the library!
}