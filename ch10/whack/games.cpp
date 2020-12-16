//  game library

#include <Adafruit_CircuitPlayground.h>
#include "games.h"

#define toneLength 500
#define minTouch 400

#define red 0xC00000
#define green 0x00C000
#define blue 0x0000C0
#define yellow 0x606000

//  global variables

int pixels[] = {1, 3, 6, 8};
int32_t colors[] = {red, blue, green, yellow};
float tones[] = {261.63, 293.66, 329.63, 349.23};

// play a note and light the pixel

void showPixel(int n) {  
  CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(pixels[n], colors[n]);
  CircuitPlayground.playTone(tones[n], toneLength, false);
}

//  clear pixel
void hidePixel() {
	  CircuitPlayground.clearPixels();
}

//  read touch pads

int readTouch(int repeat) {
  int n = 0;
      
  while (n < repeat) {
    if (CircuitPlayground.readCap(3) > minTouch) return 0;
    if (CircuitPlayground.readCap(1) > minTouch) return 1;
    if (CircuitPlayground.readCap(10) > minTouch) return 2;
    if (CircuitPlayground.readCap(6) > minTouch) return 3;
	n++;
  }

  return -1;
}

//  play win sound

void taDa() {
	 float freq = 880;
	  
  delay(500);
  CircuitPlayground.playTone(freq,  200);
  delay(50);
  CircuitPlayground.playTone(freq, 1000);
}


//  play lose tone 

void razz() {
  delay (500);
  CircuitPlayground.playTone(150, 1500);
}

