#include <Sound.hpp>
#include <Arduino.h>

Cancion::Cancion(nota_duracion* nd, int cant_notas) {
    this->nd = nd;
    this->cant_notas = cant_notas;
}

void Cancion::sonar(int pin_buzzer) {
  for (int thisNote = 0; thisNote < cant_notas; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/nd[thisNote].duracion;
    tone(pin_buzzer, nd[thisNote].nota, noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pin_buzzer);
  }
}