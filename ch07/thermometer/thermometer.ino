//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  thermometer

#include <Adafruit_CircuitPlayground.h>

//  define colors

#define blue 0x0000C0
#define green 0x00C000
#define red 0xC00000
#define brightness 200

int  pixels[] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5};

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  Serial.begin (9600);
  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setBrightness (brightness);
}

//  loop - get temperature and display
    
void loop() {   
  float temp = CircuitPlayground.temperatureF();
  int   i  = floor ((temp - 50.0) / 5.0);
  int  color = green;
  
  if (i < 0) i = 0;
  if (i >9) i = 9;
  if (temp < 65.0) color = blue;
  if (temp > 85.0) color = red;

  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setPixelColor(pixels[i], color);
  
  if (CircuitPlayground.leftButton()) {
    Serial.print("Temperature: ");
    Serial.println(temp);       
  }
  
  delay(500);
}
