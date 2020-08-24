#include <Adafruit_NeoPixel.h>

class Color {
private:
    int promedioNums(int, int, int);
public:
    int red;
    int green;
    int blue;
    Color(int r, int g, int b):
        red(r),
        green(g),
        blue(b) {};
    Color porcentajeRango(const Color&, int);
    Color()=delete;
};

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