#include "wifi.h"

const char* ssid = "TemperatureNetwork";
const char* password = "AardvarkBadgerHedgehog";

void initWifi() {
    // Connect to WiFi network
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}