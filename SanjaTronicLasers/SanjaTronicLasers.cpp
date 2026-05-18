#include "SanjaTronicLasers.h"
#include <Adafruit_VL53L0X.h>

SanjaTronicLasers::SanjaTronicLasers(SanjaTronicMultiplexI2C* mux)
{
  multiplex = mux;

  sensores[0] = &sensor0;
  sensores[1] = &sensor1;
  sensores[2] = &sensor2;
  sensores[3] = &sensor3;
  sensores[4] = &sensor4;
  sensores[5] = &sensor5;
}
void SanjaTronicLasers::iniciaLaser(int numSensor)
{
  multiplex->selecionarCanal(numSensor);

  Serial.print("Iniciando laser : ");
  Serial.println(numSensor);

  if(!sensores[numSensor]->begin())
  {
    Serial.print("falha na inicializacao no sensor: ");
    Serial.print(numSensor);
    while (1);
  }
}
float SanjaTronicLasers::getDistancia(int numSensor)
{
  VL53L0X_RangingMeasurementData_t measure;

  multiplex->selecionarCanal(numSensor);
  sensores[numSensor]->rangingTest(&measure, false);

  return measure.RangeMilliMeter / 10.0;
}