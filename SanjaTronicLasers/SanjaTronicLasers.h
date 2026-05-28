#ifndef SANJATRONICLASERS_H
#define SANJATRONICLASERS_H

#include <Adafruit_VL53L0X.h>
#include "SanjaTronicMultiplexI2C.h"

class SanjaTronicLasers
{
  private:
    SanjaTronicMultiplexI2C* multiplex;

    Adafruit_VL53L0X sensor0;
    Adafruit_VL53L0X sensor1;
    Adafruit_VL53L0X sensor2;
    Adafruit_VL53L0X sensor3;
    Adafruit_VL53L0X sensor4;
    Adafruit_VL53L0X sensor5;

    Adafruit_VL53L0X* sensores[6];

    // canais reais do multiplexador
    int canais[6] = {2, 3, 4, 5, 6, 7};

  public:
    SanjaTronicLasers(SanjaTronicMultiplexI2C* multiplex);

    void iniciaLaser(int indiceSensor);
    float getDistancia(int indiceSensor);
};

#endif