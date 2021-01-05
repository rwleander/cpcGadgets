//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  light meter

#include <Adafruit_NeoPixel.h>


//  define colors

#define blue 0x0000C0
#define green 0x00C000
#define red 0xC00000
#define brightness 200


//  pins

#ifdef __AVR__ 
  #define buttonPin 4 
  #define  sensorPin A5
  #define  pixelPin 17
#else
  #define buttonPin 4 
  #define  sensorPin A8
  #define  pixelPin 8
#endif

//  globals

Adafruit_NeoPixel pixels(10, pixelPin, NEO_GRB + NEO_KHZ800);
int  pixelMap[] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5};

//  setup  

void setup() {
  pixels.begin();
  pixels.clear();
  pinMode(buttonPin, INPUT);
  Serial.begin (9600);  
}

//  loop - get light and display
    
void loop() {   
  int light = analogRead(sensorPin);
  int   i  = light / 100;
  int  color = green;  
if (i > 9) i = 9;
if (i < 3) color = blue;
if (i > 6) color = red;

  pixels.clear(); 
  pixels.setPixelColor(pixelMap[i], color);
  pixels.show();
  
  if (digitalRead(buttonPin) == HIGH) { 
    Serial.print("Light: ");
    Serial.println(light);       
  }
  
  delay(500);
}
