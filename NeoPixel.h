//leds to remove from the end
#define SCRATCH 30

//pin leds are connected to
#define PIN 3

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

extern Adafruit_NeoPixel strip;

void clear();
void red();
void blue();
void green();
void colorWipe(uint32_t c, uint8_t wait);
void NPSetup();

void wipeCommand();
