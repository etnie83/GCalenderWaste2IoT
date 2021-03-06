/*
    Edited (C) 2018 André Geiger GCalendarWaste2IoT

    GCalendarToESP is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include <ArduinoJson.h>
#include "userconfig.h"                    // Fixed user configurable options

// =========Definitions==============
#define MICROSEC              1000000L
#define MILLISEC              1000L
#define SEC                   1L
#define MINUTE                (unsigned int) 60L*SEC
#define HOUR                  (unsigned int) 60L*MINUTE
#define DAY                   (unsigned long) 24L*HOUR

// ====================================
#define DEFAULT_POLLING_RATE  5*MINUTE
#define DEBUG                 1
// ====================================

#ifndef MY_LANGUAGE
  #include "language/de-DE.h"
#else
  #define QUOTEME(x) QUOTEME_1(x)
  #define QUOTEME_1(x) #x
  #define INCLUDE_FILE(x) QUOTEME(language/x.h)
  #include INCLUDE_FILE(MY_LANGUAGE)
#endif

#ifdef NEOPIXEL
#include "neopixel.h"
#endif // NEOPIXEL

// =========HTTPS parameters===========
#define HTTPS_PORT            443
#define HOST                  "script.google.com"
#define URL                   "https://" HOST "/macros/s/" SCRIPT_ID "/exec"
#define SUCCESS               "\"status\":\"success\""
#define MAX_WIFI_ATTEMPTS     20
#define MAX_HTTPS_ATTEMPTS    5
#define HTTPS_REINTENT_DELAY  2*SEC

// Global variables
HTTPSRedirect* client = NULL;
int _attempts = 0;
String _title = "FIRST ENTRY";      //Placeholder
String _title2 = "SECOND ENTRY";    //Placeholder
int _hour = 0;

// ==============SETUP================
void setup() {
  // Serial initialize
  serialInit();
  // Wifi initialize
  wifiInit();
#ifdef NEOPIXEL
  pixels.begin(); // This initializes the NeoPixel library.
#endif
}

// ===============LOOP================
void loop() {
  if (_attempts <= MAX_WIFI_ATTEMPTS) {
    _attempts = 0;
    String response = httpsGet();
    if (response != "") {
      process(response);
    } else nothing();
  } else nothing();

//   delay(15000);
  delay(900000); // jede 15 Minuten
//  sleep();
}

void process(String response) {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(response);
  if (root.success()) {
    String status = root["status"];
    if (status == "success") {
      _hour = root["hour"];
      String _title = root["data"]["title1"];
      String _title2 = root["data"]["title2"];
        if (_title2 == "nothing")
          {
            _title2 = _title;
          }
        #if DEBUG
          Serial.print(F(D_FIRST_WASTE_DETECTED)); Serial.println(_title);
          Serial.print(F(D_SECOND_WASTE_DETECTED)); Serial.println(_title2);
          Serial.print(F(D_ACTUAL_HOUR)); Serial.println(_hour);
        #endif
#ifdef NEOPIXEL
  if (_hour >= 13 && _hour <=23)
    {
      if (_title != "nothing")
        {
        if (_title == D_WASTE_BLUE){
          blue();
          }
        else if (_title == D_WASTE_GREEN){
          green();
          }
        else if (_title == D_WASTE_YELLOW){
          yellow();
          }
        else if (_title == D_WASTE_GREY){
          grey();
          }
        }
      else
          {
            nothing();
          }
	  if (_title2 != "nothing")
      {
        if (_title2 == D_WASTE_BLUE){
          blue2();
          }
        else if (_title2 == D_WASTE_GREEN){
          green2();
          }
        else if (_title2 == D_WASTE_YELLOW){
          yellow2();
          }
        else if (_title2 == D_WASTE_GREY){
          grey2();
          }
      }
      else
          {
            nothing();
          }
    }
    else
      {
        nothing();
      }
#endif
  }
    else {  // if wrong transmit do this
		#if DEBUG
		Serial.print(F("Unsuccessful response: ")); Serial.println(status);
		#endif
        }
  } else  {
          #if DEBUG
            Serial.println(F("Failed to parse JSON"));
          #endif
          nothing();
          }
}
