#ifndef SANJATRONICGIROSCOPIO_H
#define SANJATRONICGIROSCOPIO_H

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include "SanjaTronicMultiplexI2C.h"

class SanjaTronicGiroscopio {
  public:
    // Construtor: Recebe o ponteiro do multiplexador e o canal I2C correspondente
    SanjaTronicGiroscopio(SanjaTronicMultiplexI2C* multiplex, uint8_t c);

    // Inicializa o sensor físico BNO055. Retorna true se obtiver sucesso
    bool begin();

    // Atualiza as leituras internas. Deve ser chamado continuamente dentro dos loops de movimento
    void update();

    // Redefine o ângulo relativo atual para 0 graus
    void reset();

    // Retorna o ângulo acumulado (positivo para um lado, negativo para o outro)
    float getAngulo();

  private:
    SanjaTronicMultiplexI2C* mux; // Ponteiro para a instância do seu multiplexador
    uint8_t canal;                // Canal do MUX onde este BNO055 está conectado
    
    float anguloAnterior;         // Armazena a última leitura bruta do sensor (0-360)
    float grausVirados;           // Armazena o ângulo relativo acumulado e corrigido
};

#endif