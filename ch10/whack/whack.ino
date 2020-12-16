//  whack a pixel

#include <Adafruit_CircuitPlayground.h>
#include "games.h"

#define turns 20
#define winner  15
#define brightness 200

#ifdef __AVR__
  #define wait 500
  #define step 20
#else
  #define wait 30
  #define step 1
#endif


//  setup - set pixels on

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness (brightness);
  CircuitPlayground.clearPixels();
  randomSeed(analogRead(A0));  
}

//  loop - turn on and off pixels
    
void loop() {   
  if (CircuitPlayground.leftButton()) {
    delay(1000);
    playGame();
  }
}

//  main game loop

void playGame() {
  int winLose = 0;
  int hits = 0;
  int n = 0;
  int tone = 0;
  int w = wait;
      
  while ((n < turns) && (hits < winner)) {
    tone = random(4);
    showPixel(tone);
    if (tone == readTouch(w)) hits++;
    hidePixel();
    delay(250);
    w -= step;
    n++;
  }
  
  if (hits >= winner) {
    taDa();
  }
  else{
    razz();
} 
}
