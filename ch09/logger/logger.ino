//  log sensors to spreadsheet

#include <Adafruit_CircuitPlayground.h>
#include <Keyboard.h>

//  globals

int n = 0;

//  setup 

void setup() {
  CircuitPlayground.begin();
}

//  loop - get sensor data  and send to keyboard device
    
void loop() {   
  if (CircuitPlayground.slideSwitch()) {
    if (n > 0) {
      Keyboard.println();
      Keyboard.end();
      n = 0;
    }
  }
  else {
    if (n == 0) {
      Keyboard.begin();
      Keyboard.println("n,Temperature,Light,Sound,Accel X, Accel Y, Accel Z"); 
      delay(250);
    }
      
    float temp = CircuitPlayground.temperatureF();
    int light = CircuitPlayground.lightSensor();
    int sound = CircuitPlayground.soundSensor();
    float x = CircuitPlayground.motionX();
    float y = CircuitPlayground.motionY();
    float z  = CircuitPlayground.motionZ();

    n++;
    Keyboard.print(n);
    Keyboard.print(",");
    Keyboard.print(temp);
    Keyboard.print(",");
    Keyboard.print(light);
    Keyboard.print(",");
    Keyboard.print(sound);
    Keyboard.print(",");
    Keyboard.print(x);
    Keyboard.print(",");
    Keyboard.print(y);
    Keyboard.print(",");
    Keyboard.println(z);
    delay(10000);
  }  
}

//  send the column titles

void sendTitles() {
}


//  send the sensor values

void sendValues() {
}

