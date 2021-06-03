#include <Neurona.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "model.h"
#include "Adafruit_TCS34725.h"

/***********************************
   Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 5.0/3.3V DC
   Connect GROUND to common ground
************************************/

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MLP mlp(NET_INPUTS, NET_OUTPUTS, layerSizes, MLP::LOGISTIC, initW, true);

Adafruit_TCS34725 tcs = Adafruit_TCS34725();

void setup() {
  Serial.begin(115200);

  // Checked TCS34725 RGB sensor
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  // Checked the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
}

void loop() {
  uint16_t r, g, b, c;

  tcs.getRawData(&r, &g, &b, &c);

  double red = double(r) / 20.0;
  double green = double(g) / 20.0;
  double blue = double(b) / 20.0;

  // Fill the input buffer
  netInput[1] = red;
  netInput[2] = green;
  netInput[3] = blue;

  // Run the inferencing
  int index = mlp.getActivation(netInput);
  mlpClass = Class[index];

  // Print the output/prediction
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 0);
  display.println(Class[index]);
  display.display();
  delay(2000);
  Serial.println(mlpClass);
}
