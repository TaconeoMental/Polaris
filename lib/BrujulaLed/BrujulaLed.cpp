#include <BrujulaLed.hpp>
#include <Adafruit_NeoPixel.h>

Color Color::porcentajeRango(const Color& color2, int porcentaje) {
    Color color(promedioNums(this->red, color2.red, porcentaje), promedioNums(this->red, color2.red, porcentaje), promedioNums(this->red, color2.red, porcentaje));
    return color;
}

int Color::promedioNums(int r, int g, int b) {
    return 0;
}

void BrujulaLed::actualizarGrado(float angulo, float distancia) {
    int num_led_principal = round((fmod(angulo, 360) / 360) * (this->num_leds - 1));
    int izquierda;
    int derecha;

    izquierda = num_led_principal + 1;
    derecha = num_led_principal - 1;
    if(num_led_principal == 15) {
        izquierda = 0;
    } else if (num_led_principal == 0)
    {
        derecha = 15;
        neopixel.setPixelColor(0, color_principal.red, color_principal.green, color_principal.blue);
    }
    neopixel.setPixelColor(izquierda, color_secundario.red, color_secundario.green, color_secundario.blue);
    neopixel.setPixelColor(derecha, color_secundario.red, color_secundario.green, color_secundario.blue);
    neopixel.setPixelColor(num_led_principal, color_principal.red, color_principal.green, color_principal.blue);

    neopixel.show();
}