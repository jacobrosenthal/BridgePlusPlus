#include "NeoPixel.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(160, PIN, NEO_GRB + NEO_KHZ800);

void NPSetup(){
  
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  clear();
  strip.show(); // Initialize all pixels to 'off'
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels()-SCRATCH; i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void clear() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
}

void wipeCommand(){
//  int first, second, third, value;
//
//  // Read first number
//  first = client.parseInt();
//  second = client.parseInt();
//  third = client.parseInt();
//  value = client.parseInt();
  colorWipe(strip.Color(0, 255, 0), 50); // Green
}

void red() {
  for(uint16_t i=0; i<strip.numPixels()-SCRATCH; i++) {
    strip.setPixelColor(i, 255, 0, 0);
  }
  strip.show();
}

void green() {
  for(uint16_t i=0; i<strip.numPixels()-SCRATCH; i++) {
    strip.setPixelColor(i, 0, 255, 0);
  }
  strip.show();
}

void blue() {
  for(uint16_t i=0; i<strip.numPixels()-SCRATCH; i++) {
    strip.setPixelColor(i, 0, 0, 255);
  }
  strip.show();
}

