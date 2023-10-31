// -*-c++-*-

// --------------------------------------------------------------
//
// Mario Climent Jiménez
// 2023-09-27
//
// --------------------------------------------------------------

// --------------------------------------------------------------
// --------------------------------------------------------------
#include <bluefruit.h>

#undef min // vaya tela, están definidos en bluefruit.h y  !
#undef max // colisionan con los de la biblioteca estándar

// --------------------------------------------------------------
// --------------------------------------------------------------
#include "PuertoSerie.h"

// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales {
  
  PuertoSerie elPuerto ( /* velocidad = */ 115200 ); // 115200 o 9600 o ...

};

// --------------------------------------------------------------
// --------------------------------------------------------------
#include "EmisoraBLE.h"
#include "Publicador.h"
#include "Medidor.h"
// --------------------------------------------------------------
// --------------------------------------------------------------
namespace Globales {

  Publicador elPublicador;

  Medidor elMedidor;

}; // namespace

enum MedicionesID  {
	OZONO = 11,
	TEMPERATURA = 12,
};

// --------------------------------------------------------------
// setup()
// --------------------------------------------------------------
void setup() {

  Globales::elPuerto.escribir( "---- setup(): inicio ---- \n " );

  Globales::elPuerto.esperarDisponible();

  Globales::elPublicador.encenderEmisora();

  Globales::elMedidor.iniciarMedidor();

  esperar( 1000 );

  Globales::elPuerto.escribir( "---- setup(): fin ---- \n " );

} // setup ()


// --------------------------------------------------------------
// loop ()
// --------------------------------------------------------------
namespace Loop {
  uint8_t cont = 0;
};

// ..............................................................
// ..............................................................
void loop () {

  using namespace Loop;
  using namespace Globales;

  cont++;//Suma cada vez que el loop empieza

  elPuerto.escribir( "\n-loop(): empieza " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );

  // 
  // mido y publico
  // 
  int valorOzono = elMedidor.medirOzono();
  elPuerto.escribir( "-publicarMedicion(): OZONO" );
  elPublicador.publicarMedicion(valorOzono, 
                                MedicionesID::OZONO,// utilizamos la ID del parametro correspondiente
                                cont, 
                                2000 // intervalo de emisión
                                );
  // 
  // mido y publico
  // 
  int valorTemperatura = elMedidor.medirTemperatura();
  elPuerto.escribir( "-publicarMedicion(): TEMPERATURA" );
  elPublicador.publicarMedicion(valorTemperatura, 
                                MedicionesID::TEMPERATURA,// utilizamos la ID del parametro correspondiente
                                cont, 
                                2000 // intervalo de emisión
                                );

  esperar( 2000 );

  elPublicador.laEmisora.detenerAnuncio();
  
  // 
  // 
  // 
  elPuerto.escribir( "-loop(): acaba " );
  elPuerto.escribir( cont );
  elPuerto.escribir( "\n" );
  
} // loop ()
// --------------------------------------------------------------
// --------------------------------------------------------------