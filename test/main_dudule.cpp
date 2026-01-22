/*Balayage multicolors*/

#include "Adafruit_NeoPixel.h"
#define PIN  13
#define D0 12
#define micro A0
#define NUMPIXELS 15
unsigned long time=0;
String last_couleur;
Adafruit_NeoPixel strip (NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int val_mic =0;
int power=255;

void setup() {
   strip.begin();
   strip.setBrightness(power);  // luminosité de la LED (maximum 255)
   Serial.begin(9600);
}

void set_colors(int red,int green, int bleu,String couleur){
    if (millis() >= time+1000 && couleur != last_couleur){
        time=millis();
        last_couleur=couleur;
        Serial.print(val_mic);
        Serial.println(" "+couleur);
        for (int i =0;i < NUMPIXELS;i++){
            strip.setPixelColor(i, strip.Color(red, green, bleu));
        }
    strip.show();
    }


    
}

void loop() {


 delay(50);

val_mic= analogRead(micro);
//Serial.println(val_mic);





if (val_mic >= 540){

    set_colors(255,0,0,"red");//rouge

}
else if (val_mic >= 530){

    set_colors(255,165,0,"orange");//orange

}
else if (val_mic >= 520){

    set_colors(255,255,0,"yel");//jaune

}
else if (val_mic >= 510){

    set_colors(0,255,0,"green");//green
}
if (val_mic <= 500){

    set_colors(0,128,0,"lite green");//petit green
}

}
