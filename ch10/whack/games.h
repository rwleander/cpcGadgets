//  Arduino code for the book 'Games and Gadgets for the Circuit Playground'
//    by Rick Leander
//  Copyright (c) 2021 Rick Leander All rights reserved
//  Buy the book at https://www.amazon.com/author/rleander
//
//  game library header

#ifndef __GAMES
#define __GAMES


//  functions

void showPixel(int n);  
void showAllPixels(uint32_t color);
void hidePixel();
int readTouch(int repeat);
void taDa();
void razz();  

#endif
