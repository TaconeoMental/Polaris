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

class BrujulaLed {
private:
    Color& color_principal;
    Color& color_secundario;
    Color& color_lejano_principal;
    Color& color_lejano_secundario;

    Adafruit_NeoPixel neopixel;
public:
    BrujulaLed(const Adafruit_NeoPixel& _neopixel, Color& color_p, Color& color_s, Color& color_lejos_p, Color& color_lejos_s):
        color_principal(color_p),
        color_secundario(color_s),
        color_lejano_principal(color_lejos_p),
        color_lejano_secundario(color_lejos_s),
        neopixel(_neopixel) {
            neopixel.begin();
        };

    inline void clear(){neopixel.clear();};

    void actualizarGrado(float, float);

    // DEBUG!!!! Sacar antes de compilar oficialmente
    inline Adafruit_NeoPixel get_neopixel(){return neopixel;};
};