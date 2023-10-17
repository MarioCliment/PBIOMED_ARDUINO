# PBIOMED_ARDUINO

## Descripción del Proyecto

Este repositorio corresponde a la parte de Arduino del proyecto 3A (Biometría y Medio Ambiente). Incluye un programa principal llamado `Emison_Datos_Arduino.ino` y varias bibliotecas creadas por Jordi Bataller i Mascarell, incluyendo `EmisoraBLE.h`, `Medidor.h`, `Publicador.h`, `PuertoSerie.h` y `ServicioEnEmisora.h`.

## Contenido del Repositorio

- `Emison_Datos_Arduino.ino`: El archivo principal del programa de Arduino.

### Bibliotecas

- `EmisoraBLE.h`: Biblioteca para gestionar la emisión de datos a través de Bluetooth Low Energy (BLE).

- `Medidor.h`: Biblioteca que proporciona funciones de medición de datos.

- `Publicador.h`: Biblioteca para publicar datos a través de una interfaz específica.

- `PuertoSerie.h`: Biblioteca para la comunicación serie.

- `ServicioEnEmisora.h`: Biblioteca que define un servicio específico en la emisora.

## Placa Arduino

Antes de cargar y ejecutar el programa de Arduino, asegúrate de tener una placa SparkFun Pro nRF52840 Mini. Puedes encontrar más información sobre esta placa en la [página oficial de SparkFun Pro nRF52840 Mini](https://www.sparkfun.com/products/15025).

## Requisitos Previos

Antes de cargar y ejecutar el programa de Arduino, asegúrate de tener los siguientes requisitos previos instalados:

- [Arduino IDE](https://www.arduino.cc/en/software): Descarga e instala el entorno de desarrollo Arduino IDE en tu ordenador.

## Cómo Utilizar el Proyecto

1. Descarga la carpeta `Emision_Datos_Arduino` desde este repositorio que se encuentra dentro de src.

2. Abre el archivo `Emison_Datos_Arduino.ino` en el Arduino IDE.

3. Conecta tu placa SparkFun Pro nRF52840 Mini a tu ordenador a través de un cable USB.

4. Selecciona el modelo de tu placa Arduino en el Arduino IDE desde la pestaña "Herramientas".

5. Compila el código haciendo clic en el botón de verificación.

6. Carga el programa en tu placa Arduino haciendo clic en el botón de carga.

7. Observa la salida del programa en el monitor serie del Arduino IDE para depuración.

## Autor

- [@MarioCliment](https://www.github.com/MarioCliment)

