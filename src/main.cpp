#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
// Necesario para el anillo de Neopixels
#ifdef __AVR__
    #include "avr/power.h"
#endif
#include <BrujulaLed.hpp>
#include <canciones.hpp>

#define PIN        2
#define NUMPIXELS 16
#define DELAYVAL 500

Color color_cerca_principal(150, 0, 0);
Color color_cerca_secundario(0, 250, 0);
Color color_lejos_principal(150, 0, 0);
Color color_lejos_secundario(150, 0, 0);

BrujulaLed brujula_led(NUMPIXELS, PIN, color_cerca_principal, color_cerca_secundario, color_lejos_principal, color_lejos_secundario);

void setup() {
    // Necesario para el anillo de Neopixels
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif
}

void loop() {

}