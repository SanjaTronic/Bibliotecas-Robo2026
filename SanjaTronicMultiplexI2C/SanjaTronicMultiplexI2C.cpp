#include "SanjaTronicMultiplexI2C.h"

SanjaTronicMultiplexI2C::SanjaTronicMultiplexI2C(uint8_t addr)
{
  endereco = addr;
}

void SanjaTronicMultiplexI2C::begin()
{
  Wire.begin();
}

void SanjaTronicMultiplexI2C::selecionarCanal(uint8_t i) 
{
  Wire.beginTransmission(endereco);
  Wire.write(1 << i);
  Wire.endTransmission();
}
