//  minute timer

#include <Adafruit_CircuitPlayground.h>

//  constants

#define interval 5
#define tone 440
#define color 0x008000
#define brightness 200

//  declare functions

void setPixel();

//  global variables

int seconds = 0;
bool counting = false;

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels(); 
  CircuitPlayground.setBrightness (brightness);
}

//  loop - adjust and display seconds
    
void loop() {   

  if (CircuitPlayground.leftButton()) {
    if (counting) {
      seconds += interval;
    }
    else {
      seconds = interval;
      counting = true;
    }
  }
  
  if (CircuitPlayground.rightButton()) {
    seconds = 0;
    counting = false;
  }

  setPixel();  
  if (counting) {       
    seconds--; 
    if (seconds < 0) {
      CircuitPlayground.playTone(tone, 500, false);
    }
    }
  
    delay (1000);
  }

  
  //  show remaining minutes
  
  void setPixel() {
    int  i = seconds / interval;
    if (i < 0) i = 0;
    if (i > 9) i = 9;
	
    CircuitPlayground.clearPixels();
    if (counting) {
CircuitPlayground.setPixelColor(9 - i, color);  
    }
  }
  