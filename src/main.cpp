#include "Adafruit_NeoPixel.h"
#define PIN  13
#define NUMPIXELS 15
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
   strip.begin();
   strip.setBrightness(255);  // luminosité de la LED (maximum 255)
   Serial.begin(9600);
}

void loop() {

  for (int i =0;i < 15;i++){

    int rouge = random(15, 256);
    int vert = random(15, 256);
    int bleu = random(15, 256);

    rouge = (rouge * rouge) / 255; // Augmente les valeurs
    vert = (vert * vert) / 255;
    bleu = (bleu * bleu) / 255;

    strip.setPixelColor(i, strip.Color(rouge, vert, bleu));
    strip.show();
    delay(100);
  }
    for (int i =14;i > 0;i--){

    int rouge = random(15, 256);
    int vert = random(15, 256);
    int bleu = random(15, 256);
    
    rouge = (rouge * rouge) / 255; // Augmente les valeurs
    vert = (vert * vert) / 255;
    bleu = (bleu * bleu) / 255;
    
    strip.setPixelColor(i, strip.Color(rouge, vert, bleu));
    strip.show();
    delay(100);
  }

}