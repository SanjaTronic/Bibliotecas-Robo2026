#ifndef SANJATRONICMULTIPLEXI2C_H
#define SANJATRONICMULTIPLEXI2C_H

#include <Wire.h>

class SanjaTronicMultiplexI2C
{
  private:
    uint8_t endereco;

  public:
    SanjaTronicMultiplexI2C(uint8_t addr);
    void begin();
    void selecionarCanal(uint8_t canal);
};

#endif
