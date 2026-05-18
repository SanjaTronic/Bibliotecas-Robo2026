#ifndef SANJATRONICSENSORCOR_H
#define SANJATRONICSENSORCOR_H

#include <Arduino.h>

class SanjaTronicSensorCor
{
  private:
    int PinOUT, PinS2, PinS3;
    int red;
    int green;
    int blue;

  public:
    void definirPinos(int PinOUT, int PinS2, int PinS3);
    void cores();
    void leituraCores();
};

#endif