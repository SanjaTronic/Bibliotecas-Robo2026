#ifndef SANJATRONICGIROSCOPIO_H
#define SANJATRONICGIROSCOPIO_H

#include "SanjaTronicMultiplexI2C.h"
#include <Arduino.h>

class SanjaTronicGiroscopio
{
  private:
    SanjaTronicMultiplexI2C* mux;
    uint8_t canal;

  public:
    SanjaTronicGiroscopio(SanjaTronicMultiplexI2C* multiplex, uint8_t canal);

    void begin();
    void update();
    float getAngulo();
    void reset();
};

#endif
