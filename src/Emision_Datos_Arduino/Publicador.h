// -*- mode: c++ -*-

// --------------------------------------------------------------
// Creado por: Jordi Bataller i Mascarell (2019-07-07)
// Modificado por: Mario Climent Jimenez (2023-10-1)
// --------------------------------------------------------------

#ifndef PUBLICADOR_H_INCLUIDO
#define PUBLICADOR_H_INCLUIDO


// ----------------------------------------------------------
// ----------------------------------------------------------
void esperar (long tiempo) {
  delay (tiempo);
}

// --------------------------------------------------------------
// --------------------------------------------------------------
class Publicador {

  // ............................................................
  // ............................................................
private:

  uint8_t beaconUUID[16] = { 
	'E', 'P', 'S', 'G', '-', 'G', 'T', 'I', 
	'-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
	};

  // ............................................................
  // ............................................................
public:
  EmisoraBLE laEmisora {
	"EPSG-GTI-PROY-3A-MARIO", //  nombre emisora
	  0x004c, // fabricanteID (Apple)
	  4 // txPower
	  };
  
  const int RSSI = -53; // por poner algo, de momento no lo uso

  // ............................................................
  // ............................................................
public:

  // ............................................................
  // ............................................................
  Publicador( ) {
	// ATENCION: no hacerlo aquí. (*this).laEmisora.encenderEmisora();
	// Pondremos un método para llamarlo desde el setup() más tarde
  } // ()

  // ............................................................
  // ............................................................
  void encenderEmisora() {
	(*this).laEmisora.encenderEmisora();
  } // ()

  // ............................................................
  // ............................................................
  void publicarMedicion( float valorMedicion, uint16_t idMedicion,
							uint8_t contador, long tiempoEspera ) {

  //
	// 1. empezamos anuncio
	//
  uint16_t major = idMedicion;
	(*this).laEmisora.emitirAnuncioIBeacon( (*this).beaconUUID, 
											major,
											valorMedicion, // minor
											(*this).RSSI // rssi
									);

  Globales::elPuerto.escribir( "   publicarMedicion():" );                
  Globales::elPuerto.escribir( "   valor (minor)=" );
	Globales::elPuerto.escribir( valorMedicion );
	Globales::elPuerto.escribir( "   contador=" );
	Globales::elPuerto.escribir( contador );
	Globales::elPuerto.escribir( "   ID (major)=="  );
	Globales::elPuerto.escribir( major );
	Globales::elPuerto.escribir( "\n" );
  //
	// 2. esperamos el tiempo que nos digan
	//
	esperar( tiempoEspera );
  //
	// 3. paramos anuncio
	//
	(*this).laEmisora.detenerAnuncio();
  } // ()
	
}; // class

// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
// --------------------------------------------------------------
#endif
