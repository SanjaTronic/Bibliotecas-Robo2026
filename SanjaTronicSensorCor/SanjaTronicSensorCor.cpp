#include "SanjaTronicSensorCor.h"

void SanjaTronicSensorCor::definirPinos(int PinOUT, int PinS2, int PinS3)
{
  this->PinOUT = PinOUT;
  this->PinS2 = PinS2;
  this->PinS3 = PinS3;

  pinMode(PinOUT, INPUT);
  pinMode(PinS2, OUTPUT);
  pinMode(PinS3, OUTPUT);
}

CorDetectada SanjaTronicSensorCor::leituraCores()
{
  digitalWrite(PinS2, LOW);
  digitalWrite(PinS3, LOW);
  red = pulseIn(PinOUT, LOW, 30000);

  digitalWrite(PinS2, HIGH);
  digitalWrite(PinS3, HIGH);
  green = pulseIn(PinOUT, LOW, 30000);

  digitalWrite(PinS2, LOW);
  digitalWrite(PinS3, HIGH);
  blue = pulseIn(PinOUT, LOW, 30000);

  if (blue < 20 && red < 20 && green < 20)
  {
    return BRANCO;
  }

  else if ((red > 26 && red < 70) &&
      (green > 35 && green < 60) &&
      (blue > 22 && blue < 42))
  {
    return PRETO;
  }

  else if ((red > 12 && red < 26) &&
      (green > 24 && green < 35) &&
      (blue > 12 && blue < 17))
  {
    return AZUL;
  }

  return NENHUMA;
}