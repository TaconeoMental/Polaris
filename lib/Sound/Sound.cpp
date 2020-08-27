#include <Sound.hpp>
#include <Arduino.h>

void Tocador::tocar(const Cancion& cancion) {
  for (int thisNote = 0; thisNote < cancion.cant_notas ; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/cancion.nd[thisNote].duracion;
    tone(pin_buzzer, cancion.nd[thisNote].nota, noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pin_buzzer);
  }
}