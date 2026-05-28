#include "SanjaTronicLasers.h"

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

void SanjaTronicLasers::iniciaLaser(int indiceSensor)
{
  // proteção contra índice inválido
  if(indiceSensor < 0 || indiceSensor > 5)
  {
    Serial.println("Indice de sensor invalido");
    return;
  }

  // seleciona o canal REAL do TCA
  multiplex->selecionarCanal(canais[indiceSensor]);

  Serial.print("Iniciando laser indice: ");
  Serial.print(indiceSensor);

  Serial.print(" no canal: ");
  Serial.println(canais[indiceSensor]);

  if(!sensores[indiceSensor]->begin())
  {
    Serial.print("Falha no sensor: ");
    Serial.println(indiceSensor);

    while(1);
  }

  Serial.println("Sensor iniciado com sucesso");
}

float SanjaTronicLasers::getDistancia(int indiceSensor)
{
  if(indiceSensor < 0 || indiceSensor > 5)
  {
    Serial.println("Indice de sensor invalido");
    return -1;
  }

  VL53L0X_RangingMeasurementData_t measure;

  multiplex->selecionarCanal(canais[indiceSensor]);

  sensores[indiceSensor]->rangingTest(&measure, false);

  return measure.RangeMilliMeter / 10.0;
}