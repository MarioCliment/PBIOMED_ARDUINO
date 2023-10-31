// -*- mode: c++ -*-

// --------------------------------------------------------------
//
// Creado por: Jordi Bataller i Mascarell (2019-07-07)
// Modificado por: Mario Climent Jimenez  (2023-10-29)
//
// --------------------------------------------------------------

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO

// ------------------------------------------------------
// ------------------------------------------------------
class Medidor {

// .....................................................
// .....................................................
private:

//Definir pines
enum PINES{
  gasPin = 5,
  refPin = 28,
  tempPin = 29,
}; // enum

//Funcion para normalizar valores
// .....................................................
// valor:float --> normalizar() --> float
// .....................................................
float normalizar(float valor){
  float respuesta = (valor*3.3)/pow(2,12);
  return respuesta;
} // ()

//Funcion para calcular la temperatura detectada por el sensor con la ecuacion del datasheet
// .....................................................
// valor:float --> calcularTemperatura() --> float
// .....................................................
float calcularTemperatura(float valor){
  float temperatura = 87*valor-18;
  if (temperatura>20) {
    float correccion=(temperatura-20)*0.3;
    temperatura = temperatura-correccion;
  }
  return temperatura;
} // ()

public:

  // .....................................................
  // constructor
  // .....................................................
  Medidor(  ) {
  } // ()

  // .....................................................
  // iniciarMedidor()
  // .....................................................
  //Establecemos los valores para los pines del sensor
  void iniciarMedidor() {
    pinMode(PINES::gasPin, INPUT);
    pinMode(PINES::refPin, INPUT);
    pinMode(PINES::tempPin, INPUT);
  } // ()

  // .....................................................
  //  medirOzono() --> float
  // .....................................................
  float medirOzono() {
    //Guardar la lectura analogica en una variable
    float vGas = analogRead(gasPin);
    float vRef = analogRead(refPin);

    //Normalizar la lectura anterior con la llamada a la funcion normalizar
    float vGasN = normalizar(vGas);
    float vRefN = normalizar(vRef);

    //Calculamos vMedida
    float vMedida = vGasN-vRefN;

    //Calculamos la concentracion
    float concentracion = vMedida/(-41.26*499*pow(10,-6));

    return concentracion;
  } // ()

  // .....................................................
  // medirTemperatura() --> float
  // .....................................................
  float medirTemperatura() {
    //Guardar la lectura analogica en una variable
    float vTemp = analogRead(tempPin);

    //Normalizar la lectura anterior con la llamada a la funcion normalizar
    float vTempN = normalizar(vTemp);

    //Calcular la temperatura detectada por el sensor con la ecuacion del datasheet
    float temperatura = calcularTemperatura(vTempN);

    return temperatura;
  } // ()
	
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
