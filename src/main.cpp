/*Balayage k200*/

/*
strip.setPixelColor(led, strip.Color(255, 0, 0));
    strip.show();
*/

#include "Adafruit_NeoPixel.h"
#define PIN 13
#define NUMPIXELS 144
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int power =100; 
int qlenght = 20;
int qstep = power/qlenght;

void setup() {
   strip.begin();
   strip.setBrightness(power);  // luminosité de la LED (maximum 255)
   Serial.begin(9600);
}



void loop() {

  for (int led =21;led < NUMPIXELS;led++){
    for (int q =20 ;q > 0;q--){
      strip.setPixelColor(led-q, strip.Color(0, 0, power-int(q*qstep)));
    }
    strip.show();
    delay(10);
    strip.clear();
  }
    
  for (int i =NUMPIXELS-1;i > 0;i--){
    
  }

}
