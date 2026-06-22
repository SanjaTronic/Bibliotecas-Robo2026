#include "SanjaTronicGiroscopio.h"
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "SanjaTronicMultiplexI2C.h"

// Instância global ou interna do BNO055 (Garanta que 'bno' esteja declarado corretamente no seu .h ou aqui)
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x29, &Wire);

SanjaTronicGiroscopio::SanjaTronicGiroscopio(SanjaTronicMultiplexI2C* multiplex, uint8_t c)
{
  mux = multiplex;
  canal = c;
  grausVirados = 0.0;
  anguloAnterior = 0.0;
}

bool SanjaTronicGiroscopio::begin()
{
  mux->selecionarCanal(canal);
  delay(100);

  // Inicializa o sensor físico e retorna se deu certo ou não
  if (!bno.begin((adafruit_bno055_opmode_t)0X08)) {
    return false; 
  }

  delay(500);
  bno.setExtCrystalUse(true);

  // Define o ponto de partida inicial
  reset(); 
  return true;
}

void SanjaTronicGiroscopio::reset()
{
  mux->selecionarCanal(canal);
  
  // Captura o ângulo atual do sensor como a nova referência nula
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  anguloAnterior = euler.x();
  
  // Zera o contador relativo
  grausVirados = 0.0; 
}

void SanjaTronicGiroscopio::update()
{
  mux->selecionarCanal(canal);

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  float anguloAtual = euler.x(); 

  // Calcula a variação rápida (delta)
  float delta = anguloAtual - anguloAnterior;

  // Corrige a transição da linha de 360/0 graus
  if (delta > 180.0)  delta -= 360.0;
  if (delta < -180.0) delta += 360.0;

  // Acumula continuamente o quanto o robô girou desde o último reset
  grausVirados += delta;
  
  // Atualiza a referência para a próxima leitura
  anguloAnterior = anguloAtual; 
}

float SanjaTronicGiroscopio::getAngulo()
{
  // Retorna o valor acumulado e tratado matematicamente
  return grausVirados; 
}