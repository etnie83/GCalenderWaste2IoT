// ==========SERIAL INIT=============
void serialInit(void) {
#if DEBUG
  Serial.begin(9600);
  Serial.println();
#endif
}
