/*Balayage multicolors*/

#include "Adafruit_NeoPixel.h"
#define PIN  13
#define D0 12
#define micro A0
#define NUMPIXELS 15
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int val_mic =0;
int power=255;

void setup() {
   strip.begin();
   strip.setBrightness(power);  // luminosité de la LED (maximum 255)
   Serial.begin(9600);
}

void set_colors(int red,int green, int bleu){
    
  for (int i =0;i < NUMPIXELS;i++){
    strip.setPixelColor(i, strip.Color(red, green, bleu));
    
  }
strip.show();
    
}

void loop() {

 
 set_colors(0,255,0);
 delay(50);

val_mic= analogRead(micro);
Serial.println(val_mic);
if (val_mic >= 525){
    Serial.println(val_mic);
    set_colors(255,0,0);
    delay(1000);
}

}
