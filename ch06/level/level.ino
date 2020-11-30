//  level

#include <Adafruit_CircuitPlayground.h>

//  constants

#define level 1.0
#define color 0x00C000
#define brightness 200
#define tone 440

//  global variables

float x = 0.0;
float y = 0.0;

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setBrightness (brightness);    
}  

//  loop - read accelerometer and display highest pixel
    
void loop() {   
  CircuitPlayground.clearPixels();

//  read accelerometer

  x = CircuitPlayground.motionX();
  y = CircuitPlayground.motionY();

//  determine left or right

  switch (getPitch(x)) {
    case -1:
      checkLeft();
      break;
    case 1:
      checkRight();
      break;
    case 0:
      checkCenter();
      break;
  }
 
  delay (500);
}

//  set pixels when tilt is towards the left

void checkLeft() {
  switch (getPitch(y)) {
    case 1:
      CircuitPlayground.setPixelColor(0, color);
      CircuitPlayground.setPixelColor(1, color);
      break;
    case 0:
      CircuitPlayground.setPixelColor(2, color);
      break;
    case -1:
      CircuitPlayground.setPixelColor(3, color);
      CircuitPlayground.setPixelColor(4, color);
      break;
  }
}

// horizontal level

void checkCenter() {
  switch(getPitch(y)) {
    case 1: 
      CircuitPlayground.setPixelColor(0, color);
      CircuitPlayground.setPixelColor(9, color);
      break;
    case 0:
      CircuitPlayground.playTone(tone, 250, false);
      break;
    case -1:
      CircuitPlayground.setPixelColor(4, color);
      CircuitPlayground.setPixelColor(5, color);
      break;
  }
}

//  tilt to the right

void checkRight() {
  switch (getPitch(y)) {
    case 1: 
      CircuitPlayground.setPixelColor(9, color);
      CircuitPlayground.setPixelColor(8, color);
      break;
    case 0:
      CircuitPlayground.setPixelColor(7, color);
      break;
    case -1:
      CircuitPlayground.setPixelColor(6, color);
      CircuitPlayground.setPixelColor(5, color);
      break;
  }
}

//  see if accelerometer value is positive (1), negative (-1) or level (0)

int getPitch (float a){
  if (a > level) return 1;
  if (a < (0 - level)) return -1;
  return 0;
}

