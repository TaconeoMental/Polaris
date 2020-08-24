#include <Sound.hpp>

nota_duracion bb[6] =   {
  {NOTE_E7, 8},
  {NOTE_CS7, 8},
  {NOTE_E7, 8},
  {NOTE_CS7, 8},
  {NOTE_E7, 8},
  {NOTE_CS7, 8}
};

nota_duracion sonido1[6] =   {
  {NOTE_F7, 10},
  {NOTE_D7, 5},
  {NOTE_F7, 10},
  {NOTE_D7, 5},
  {NOTE_F7, 10},
  {NOTE_D7, 5}
};

nota_duracion att[5] =   {
  {NOTE_F7, 10},
  {NOTE_D7, 5},
  {NOTE_F7, 15},
  {NOTE_G7, 15},
  {NOTE_C8, 15}
};

nota_duracion atencion4[2] =   {
  {NOTE_FS7, 35},
  {NOTE_G7, 5},
};

nota_duracion menu[1] =  {
  {NOTE_G7, 5}
};

namespace Canciones {
    Cancion atencion2(atencion4, 2);
    Cancion atencion(att, 5);
    Cancion alarma_1(sonido1, 6);
    Cancion baja_bateria(bb, 6);
};

// For testing
Cancion canciones_test[4] {
    Canciones::atencion2,
    Canciones::atencion,
    Canciones::alarma_1,
    Canciones::baja_bateria
};