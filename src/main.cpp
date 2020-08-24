#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
//#include <SD.h>
#include "SdFat.h"

// Necesario para el anillo de Neopixels
#ifdef __AVR__
    #include "avr/power.h"
#endif
#include <BrujulaLed.hpp>
#include <canciones.hpp>

#define PIXELPIN  5
#define NUMPIXELS 16

BrujulaLed brujula_led(NUMPIXELS, PIXELPIN, color_cerca_principal, color_cerca_secundario, color_lejos_principal, color_lejos_secundario);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));
    // Necesario para el anillo de Neopixels
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif
}

void loop() {
}