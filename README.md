# GCalendarToESP
An Arduino-Project to display waste dates from google calendar with an ESP

The GoogleScript must included in your GoogleDrive and need to modified the GoogleCalendarName

The project is constantly being developed and gets even more features. Likewise, the language "Hessian" is included

Please edit your settings only in the userconfig.h

Enable Neopixel:
Uncomment NEOPIXEL into userconfig.h
Edit the PIN from the GPIO
Edit the NUMPIXELS to the installed Pixelsnumber from your installation

Enable Telegram:
Uncomment NEOPIXEL into userconfig.h
Edit the TELEGRAMTOKEN

The waste titles need to edit to your Calendar Notifications in the language file
//#############
// Waste titles
//#############
define D_WASTE_BLUE   "Altpapier"
define D_WASTE_GREEN  "Bioabfall"
define D_WASTE_YELLOW "Gelbe Tonne"
define D_WASTE_GREY   "Restabfall"
