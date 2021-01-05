//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  memory game

#include <Adafruit_CircuitPlayground.h>

#define winner  10
#define toneLength 500
#define minTouch 400

#define red 0xC00000
#define green 0x00C000
#define blue 0x0000C0
#define yellow 0x606000
#define brightness 200

//  global variables

int pixels[] = {1, 3, 6, 8};
int32_t colors[] = {red, blue, green, yellow};
float tones[] = {261.63, 293.66, 329.63, 349.23};

int notes[11];
int n = 0;

//  setup  

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness (brightness);
  CircuitPlayground.clearPixels();
  randomSeed(analogRead(A0));  
}

//  loop  
    
void loop() {   
  if (CircuitPlayground.leftButton()) {
    delay(1000);
    playGame();
  }
}


//  main game loop

void playGame() {
  int winLose = 0;
  n = 0;
      
  while (winLose == 0) {
    if (addNote()) {
      winLose = 1;
    }
    else {
      delay (1000);
      playNotes();
      if (readNotes() == false) {
        winLose = -1;
      }
    }
  }
          
  if (winLose == 1) {
    taDa();
  }
  else {  
    razz();
}
}

//  add a note to the list

bool addNote() {
  notes[n] = random(4);
  n++;
  return n > winner;    
}

// play the notes and light the pixels

void playNotes() {  
  int t; 
  
  for (int i = 0; i < n; i++) {
    t = notes[i];           
    CircuitPlayground.clearPixels();
    CircuitPlayground.setPixelColor(pixels[t], colors[t]);
    CircuitPlayground.playTone(tones[t], toneLength);
    CircuitPlayground.clearPixels();
  }   
}

//  read the sequence

bool readNotes() {
  int t;
  int i = 0;
      
  while (i < n) {
    t = notes[i];
    if (readTouch() != t) {
      return false;
    }
    
    i++;
  }
  
  return true;
}


//  read touch pads

int readTouch() {
  int t = -1;
      
  while (t < 0) {
    if (CircuitPlayground.readCap(3) > minTouch) t = 0;
    if (CircuitPlayground.readCap(1) > minTouch) t = 1;
    if (CircuitPlayground.readCap(10) > minTouch) t = 2;
    if (CircuitPlayground.readCap(6) > minTouch) t = 3;
  }

  CircuitPlayground.clearPixels();      
  CircuitPlayground.setPixelColor(pixels[t], colors[t]);
  CircuitPlayground.playTone (tones[t], toneLength);
  CircuitPlayground.clearPixels();
  return t;
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

