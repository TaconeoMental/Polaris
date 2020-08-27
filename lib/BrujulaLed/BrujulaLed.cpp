#include <BrujulaLed.hpp>
#include <Adafruit_NeoPixel.h>


int Color::porcentajeRango(int color1, int color2, int porcentaje) {
    Serial.println((porcentaje * (color1 - color2) / 100) + color2);
    return (porcentaje * (color1 - color2) / 100) + color2;
}


Color Color::porcentajeColor(const Color& color2, int porcentaje) {
    Color color(Color::porcentajeRango(this->red, color2.red, porcentaje), Color::porcentajeRango(this->green, color2.green, porcentaje), Color::porcentajeRango(this->blue, color2.blue, porcentaje));
    return color;
}

void BrujulaLed::actualizarGrado(float angulo, float distancia) {
    this->clear();
    int num_led_principal = round((fmod(angulo, 360) / 360) * (neopixel.numPixels() - 1));
    int izquierda;
    int derecha;

    izquierda = num_led_principal + 1;
    derecha = num_led_principal - 1;
    if(num_led_principal == 15) {
        izquierda = 0;
    } else if (num_led_principal == 0)
    {
        derecha = 15;
    }
    Color color_principal_porcentaje = color_principal.porcentajeColor(this->color_lejano_principal, distancia);
    Color color_secundario_porcentaje = color_secundario.porcentajeColor(this->color_lejano_secundario, distancia);

    neopixel.setPixelColor(izquierda, color_secundario_porcentaje.red, color_secundario_porcentaje.green, color_secundario_porcentaje.blue);
    neopixel.setPixelColor(derecha, color_secundario_porcentaje.red, color_secundario_porcentaje.green, color_secundario_porcentaje.blue);
    neopixel.setPixelColor(num_led_principal, color_principal_porcentaje.red, color_principal_porcentaje.green, color_principal_porcentaje.blue);

    neopixel.show();
}