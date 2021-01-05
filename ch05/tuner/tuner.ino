//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  guitar tuner

#include <Adafruit_CircuitPlayground.h>

//  frequencies

#define D 293.66
#define E 329.63
#define G 392.00
#define A 440.00
#define B 493.88

float strings[] = {E / 2, A / 2, D, G, B, E * 2};
int i = 0;

//  setup  

void setup() {
  CircuitPlayground.begin();
}

//  loop - check buttons
    
void loop() {   
   if (CircuitPlayground.leftButton()) {
      CircuitPlayground.playTone (strings[i], 1000);
   }
    
   if (CircuitPlayground.rightButton()) {
     i++;  
     if (i > 5) {
       i = 0;
     }
    CircuitPlayground.playTone(strings[i], 1000);
  }       
}
