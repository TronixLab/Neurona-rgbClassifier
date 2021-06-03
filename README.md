# Neurona-rgbClassifier
A simple RGB color classifier implementation for Arduino AVR boards and other compatible microcontrollers. This repository makes use of the [Neurona](https://www.arduino.cc/reference/en/libraries/neurona/) library for Arduino, which enables the use of a [Multilayer Perceptron](https://deepai.org/machine-learning-glossary-and-terms/multilayer-perceptron) (MLP) / Feed-forward Neural Network, a Machine Learning algorithm that can be run on Arduino boards. This library comes with the [MLP topology workbench](http://www.moretticb.com/MTW/), which is used to train the model, and the Neurona library, which is used to convert the model into simple C++ code. Thanks to [Caio Benatti Moretti's](https://scholar.google.com/citations?user=0_3GTWkAAAAJ&hl=it) brilliant work.

## Dependencies
Install the following Arduino libraries
* [Neurona](https://github.com/moretticb/Neurona) library
* [Adafruit TCS43725](https://github.com/adafruit/Adafruit_TCS34725) RGB color sensor library
* [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) OLED display library
* [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library) library

## Schematic Diagram
![GitHub Logo](https://github.com/TronixLab/Neurona-rgbClassifier/blob/main/docx/Schematic.png)

## Video Tuturoial on YouTube
[![GitHub Logo](https://github.com/TronixLab/Neurona-rgbClassifier/blob/main/docx/YouTube.jpg)](https://www.youtube.com/watch?v=MxXGnBHJJXo)

