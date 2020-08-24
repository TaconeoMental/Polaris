#include <Adafruit_NeoPixel.h>
//TODO: Implementar todo esto con FastLED.h
class Color {
public:
    int red;
    int green;
    int blue;
    Color(int r, int g, int b):
        red(r),
        green(g),
        blue(b) {};
    Color porcentajeColor(const Color&, int);
    static int porcentajeRango(int, int, int);
    Color()=delete;
};

// Dejar que el usuario cambie estos valores?
Color color_cerca_principal(255, 0, 0); 
Color color_cerca_secundario(255, 100, 0);
Color color_lejos_principal(0, 200, 250);
Color color_lejos_secundario(0, 0, 250);

class BrujulaLed {
private:
    int num_leds;
    int pin_leds;
    Color& color_principal;
    Color& color_secundario;
    Color& color_lejano_principal;
    Color& color_lejano_secundario;

    Adafruit_NeoPixel neopixel;
public:
    BrujulaLed(int _num_leds, int pin, Color& color_p, Color& color_s, Color& color_lejos_p, Color& color_lejos_s):
        num_leds(_num_leds),
        pin_leds(pin),
        color_principal(color_p),
        color_secundario(color_s),
        color_lejano_principal(color_lejos_p),
        color_lejano_secundario(color_lejos_s) {
            neopixel = Adafruit_NeoPixel(num_leds, pin, NEO_GRB + NEO_KHZ800);
            neopixel.begin();
        };

    inline void clear(){neopixel.clear();};

    void actualizarGrado(float, float);

    // DEBUG!!!! Sacar antes de compilar oficialmente
    inline Adafruit_NeoPixel get_neopixel(){return neopixel;};
};