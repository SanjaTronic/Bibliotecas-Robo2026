#ifndef SANJATRONICSENSORCOR_H
#define SANJATRONICSENSORCOR_H

#include <Arduino.h>

enum CorDetectada
{
    NENHUMA,
    BRANCO,
    PRETO,
    AZUL
};

class SanjaTronicSensorCor
{
  private:
    int PinOUT, PinS2, PinS3;
    int red, green, blue;

  public:
    void definirPinos(int PinOUT, int PinS2, int PinS3);

    CorDetectada leituraCores();
};

#endif