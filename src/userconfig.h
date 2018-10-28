//##############################################
// USERCONFIG
//##############################################

#ifndef _USER_CONFIG_H_
#define _USER_CONFIG_H_

// -- Localization --------------------------------
  // If non selected the default de-DE will be used
  // ATTENTION: The Definition of the GoogleCalendar Entrys must edited in the Localization-File for autodetect the Waste Bin
//#define MY_LANGUAGE            de-DE           // German in Germany
//#define MY_LANGUAGE            he-HE           // Platt in Hessisch_Platt

// -- WLAN Settings -------------------------------
#define SSID                  "YOUR-SSID"
#define PASSWORD              "YOUR-PASSWORD"

//  -- Script Settings of Google ------------------
#define SCRIPT_ID             "AKfycbzT_nKD6v1HU5JYh3CK_malBFk5v_PT6u_hVoasiA7XpMLHZYQ" // Edit this Key to your own from google script

#define NEOPIXEL
// -- Neopixel Definitions ------------------------
  #ifdef NEOPIXEL
    #include <Adafruit_NeoPixel.h>
    #define PIN            2
    #define NUMPIXELS      8
  #endif
// ------------------------------------------------

#endif // _USER_CONFIG_H_
