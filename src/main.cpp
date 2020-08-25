#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
//#include <SD.h>
//#include "SdFat.h"
#include <QMC5883L.h>
#include <Wire.h>

#include <BrujulaLed.hpp>
#include <canciones.hpp>


// Necesario para el anillo de Neopixels
#ifdef __AVR__
    #include "avr/power.h"
#endif
#define PIXELPIN  5
#define NUMPIXELS 16

// Dejar que el usuario cambie estos valores?
Color color_cerca_principal(255, 0, 0); 
Color color_cerca_secundario(255, 100, 0);
Color color_lejos_principal(0, 200, 250);
Color color_lejos_secundario(0, 0, 250);

QMC5883L brujula;
BrujulaLed brujula_led(NUMPIXELS, PIXELPIN, color_cerca_principal, color_cerca_secundario, color_lejos_principal, color_lejos_secundario);

void setup() {
    Serial.begin(9600);
    // Necesario para el anillo de Neopixels
    #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
        clock_prescale_set(clock_div_1);
    #endif
    /*
    Wire.begin();
	brujula.init();
	brujula.setSamplingRate(10);
    brujula.resetCalibration();
    */
}

void loop() {
}