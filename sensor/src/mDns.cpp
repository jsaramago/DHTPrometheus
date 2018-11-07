#include "mDns.h"

void initMDns(const char* hostname) {
    if (!MDNS.begin("esp8266-0")) {
        Serial.println("Error setting up MDNS responder!");
        while (1) {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");
}