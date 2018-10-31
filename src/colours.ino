// ==========NOTHING TO DO==============
void nothing(void) {
  for(int i=0;i<NUMPIXELS;i++){

    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}
// ==========BLUE==============
void colourchange(int a, int b, int c, int d) {
    for(int i=0;i<(NUMPIXELS/d);i=i+2)
      {
        pixels.setPixelColor(i, pixels.Color(a,b,c)); // Moderately bright color.
        pixels.show(); // This sends the updated pixel color to the hardware.
      }
}
