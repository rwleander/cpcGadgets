//  light meter

#include <Adafruit_NeoPixel.h>


//  define colors

#define blue 0x0000C0
#define green 0x00C000
#define red 0xC00000
#define brightness 200


//  pins

#define buttonPin 4 
#define  sensorPin A5
#define  pixelPin 17

//  globals

Adafruit_NeoPixel pixels(10, pixelPin, NEO_GRB + NEO_KHZ800);
int  pixelMap[] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5};

//  setup - set pixels on

void setup() {
	  pixels.begin();
	  pixels.clear();
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin (9600);  
}

//  loop - get temperature and display
    
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
  
  if (digitalRead(buttonPin)) { 
    Serial.print("Light: ");
    Serial.println(light);       
  }
  
  delay(500);
}
