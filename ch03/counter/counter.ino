//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//   counter

#include <Adafruit_CircuitPlayground.h>

//  constants

#define color 0x008000
#define brightness 200
#define clickTone 440
#define clearTone 220

//  global variables

int n = 0;

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setBrightness (brightness);  
}  
 
//  loop - count when buttons are pressed
    
void loop() {   
  if (CircuitPlayground.leftButton()) {
    n++;    
    CircuitPlayground.playTone (clickTone, 200);
  }  
  
  if (CircuitPlayground.rightButton()) {
    n = 0;
    CircuitPlayground.playTone (clearTone, 500);
  }

  if (CircuitPlayground.slideSwitch()) {
    setPixel((n / 10) % 10); 
  }
  else {
    setPixel (n % 10);          
  }

  delay(250);
}
  
//  set pixel starting with 1 on the top left, rounding to 0 on the top right

void setPixel(int i) {
  CircuitPlayground.clearPixels();
  if (i > 0) {
    CircuitPlayground.setPixelColor(i - 1, color);          
  }
  else{
    CircuitPlayground.setPixelColor(9, color);          
  }
}
  