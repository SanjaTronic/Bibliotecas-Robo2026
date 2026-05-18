#include "SanjaTronicGiroscopio.h"
#include "mpu6050.h"

SanjaTronicGiroscopio::SanjaTronicGiroscopio(SanjaTronicMultiplexI2C* multiplex, uint8_t c)
{
  mux = multiplex;
  canal = c;
}

void SanjaTronicGiroscopio::begin()
{
  mux->selecionarCanal(canal);

  mpu_begin();
  mpu_calibrate(200);
  mpu_reset();
}

void SanjaTronicGiroscopio::update()
{
  mux->selecionarCanal(canal);
  mpu_loop();
}

float SanjaTronicGiroscopio::getAngulo()
{
  return getAngleZ();
}

void SanjaTronicGiroscopio::reset()
{
  mux->selecionarCanal(canal);
  mpu_reset();
}
