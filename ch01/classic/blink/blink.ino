//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  blink

#include <Adafruit_CircuitPlayground.h>

#define color 0x808080

//  setup - clear pixels

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  CircuitPlayground.setBrightness(128);
}

//  loop - turn pixels on and off_type

void loop() {
  setPixels();
  delay(500);
  CircuitPlayground.clearPixels();
  delay(500);
}

//  set all pixels to defined color

void setPixels() {
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, color);
  }
}
