#include <Wire.h>
#include "Adafruit_TCS34725.h"

/***********************************
   Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 5.0/3.3V DC
   Connect GROUND to common ground
************************************/

Adafruit_TCS34725 tcs = Adafruit_TCS34725();

void setup(void) {
  Serial.begin(115200);

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void loop(void) {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  double red = double(r) / 20.0;
  double green = double(g) / 20.0;
  double blue = double(b) / 20.0;

  Serial.print(red); Serial.print(",");
  Serial.print(green); Serial.print(",");
  Serial.print(blue);
  Serial.println();
}
