#define DEBUG_ESP_MDNS
#include <ESP8266mDNS.h>

#ifndef M_DNS_H
#define M_DNS_H

void initMDns(const char* hostname);

#endif /* M_DNS_H */