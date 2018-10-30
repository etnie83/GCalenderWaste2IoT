// ==========NOTHING TO DO==============
void nothing(void) {
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
// ==========BLUE==============
void blue(void) {
    for(int i=0;i<(NUMPIXELS/2);i=i+2)
      {
        pixels.setPixelColor(i, pixels.Color(0,35,255)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
}
void blue2(void) {
    for(int i=(NUMPIXELS/2);i<NUMPIXELS;i=i+2)
      {
        pixels.setPixelColor(i, pixels.Color(0,35,255)); // Moderately bright green color.
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
}
// ==========YELLOW==============
void yellow(void) {
    for(int i=0;i<(NUMPIXELS/2);i=i+2){

    pixels.setPixelColor(i, pixels.Color(255,255,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
void yellow2(void) {
    for(int i=(NUMPIXELS/2);i<NUMPIXELS;i=i+2){

    pixels.setPixelColor(i, pixels.Color(255,255,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
// ==========GREY==============
void grey(void) {
    for(int i=0;i<(NUMPIXELS/2);i=i+2){

    pixels.setPixelColor(i, pixels.Color(160,160,160)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
void grey2(void) {
    for(int i=(NUMPIXELS/2);i<NUMPIXELS;i=i+2){

    pixels.setPixelColor(i, pixels.Color(160,160,160)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
// ==========GREEN==============
void green(void) {
    for(int i=0;i<(NUMPIXELS/2);i=i+2){

    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
void green2(void) {
    for(int i=(NUMPIXELS/2);i<NUMPIXELS;i=i+2){

    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    }
}
