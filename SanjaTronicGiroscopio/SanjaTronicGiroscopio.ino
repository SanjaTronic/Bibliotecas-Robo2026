/*
virar à direita diminui o angulo
virar à esquerda aumenta o angulo
*/

#include "SanjaTronicMultiplexI2C.h"
#include "SanjaTronicGiroscopio.h"

SanjaTronicMultiplexI2C multiplex(0x70);
SanjaTronicGiroscopio giro(&multiplex, 1);

void setup()
{
  Serial.begin(9600);

  multiplex.begin();
  delay(1000);

  giro.begin();
}

void loop()
{
  giro.update();

  float angulo = giro.getAngulo();

  Serial.println(angulo);

  if (angulo > 66 || angulo < -66)
  {
    Serial.println("Resetando...");
    delay(1000);
    giro.reset();
  }

  delay(100);
}
