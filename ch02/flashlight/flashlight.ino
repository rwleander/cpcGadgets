//  flashlight with on/off switch  

#include <Adafruit_CircuitPlayground.h>

//  define pixel parameters

#define color 0xFFFFFF
#define brightness 200

//  global variables

bool isLit = false;

//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness (brightness);
  setPixels();
}

//  loop - turn on and off pixels
    
void loop() {   
  if (CircuitPlayground.slideSwitch()) { 
    clearPixels();
  }
  else {
    setPixels();
  }  
}

//  set pixels  on

void setPixels() {
  if (isLit == false) {    
    for (int i=0; i<10; i++) {
      CircuitPlayground.setPixelColor(i, color); 
    }    
	}
    isLit = true;
}

//  clear pixels

void clearPixels() {
  if (!isLit) {
    CircuitPlayground.clearPixels();
  }
  isLit = false;
}
