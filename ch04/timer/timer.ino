//  minute timer

#include <Adafruit_CircuitPlayground.h>

//  constants

#define interval 5
#define tone 440
#define color 0x008000
#define brightness 200

//  global variables

int seconds = 0;
bool isActive = false;

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setBrightness (brightness);
}

//  loop - adjust and display seconds
    
void loop() {   
  if (CircuitPlayground.leftButton()) {
    if (isActive) {
      seconds += interval;
    }
    else {
      seconds = interval;
      isActive = true;
    }
  }
  
  if (CircuitPlayground.rightButton()) {
    seconds = 0;
    isActive = false;
  }

  setPixel();  
  if (isActive) {       
    seconds--; 
    if (seconds < 0) {
      CircuitPlayground.playTone(tone, 500, false);
    }
  }
  
  delay (1000);
}
  
  //  show remaining intervals
  
  void setPixel() {
    CircuitPlayground.clearPixels();    
    if (isActive) {
      int  i = seconds / interval;
	  if (i < 0) i = 0;
      if (i > 9) i = 9;
      CircuitPlayground.setPixelColor(9 - i, color);
  } 
  }
  