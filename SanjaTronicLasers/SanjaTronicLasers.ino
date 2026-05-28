#include <Wire.h>

#include "Adafruit_VL53L0X.h"
#include "SanjaTronicMultiplexI2C.h"
#include "SanjaTronicLasers.h"

SanjaTronicMultiplexI2C multiplex(0x70);
SanjaTronicLasers lasers(&multiplex);

void setup()
{
  Serial.begin(9600);

  Wire.begin();

  // agora os índices vão de 0 até 5
  lasers.iniciaLaser(0); // canal 2 (lateral esquerda trás)
  lasers.iniciaLaser(1); // canal 3 (lateral esquerda frente)
  lasers.iniciaLaser(2); // canal 4 (sensor frontal lado esquerdo)
  lasers.iniciaLaser(3); // canal 5 (sensor frontal lado direito)
  lasers.iniciaLaser(4); // canal 6 (lateral direita frente)
  lasers.iniciaLaser(5); // canal 7 (lateral direita trás)
}

void loop()
{
  testarDireita();
}

// Funções auxiliares
void testarFrente()
{
  float frenteA = lasers.getDistancia(2);
  float frenteB = lasers.getDistancia(3);

  Serial.print("frenteA: ");
  Serial.println(frenteA);

  Serial.print("frenteB: ");
  Serial.println(frenteB);
}
void testarEsquerda()
{
  float esquerdoA = lasers.getDistancia(0);
  float esquerdoB = lasers.getDistancia(1);

  Serial.print("esquerdoA: ");
  Serial.println(esquerdoA);

  Serial.print("esquerdoB: ");
  Serial.println(esquerdoB);

  delay(100);
}
void testarDireita()
{
  float direitaA = lasers.getDistancia(5);
  float direitaB = lasers.getDistancia(4);

  Serial.print("direitaA: ");
  Serial.println(direitaA);

  Serial.print("direitaB: ");
  Serial.println(direitaB);
}