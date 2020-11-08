#include "../include/wifiControl.h"

void startWiFiManager()
{
    WiFi.setAutoReconnect(true);
    WiFiManager wifiManager;
    wifiManager.setDebugOutput(false);
    if (!wifiManager.autoConnect("Enter Credentials", "password"))
    {
        Serial.println("failed to connect, we should reset as see if it connects");
        delay(3000);
        ESP.reset();
        delay(5000);
    }
}

boolean wifiConnected()
{
    return WiFi.status() != WL_CONNECTED;
}
