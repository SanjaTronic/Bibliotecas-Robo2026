// Incluindo biblotecas
#include "SanjaTronicMotores.h"

// Criando objeto da classe Motores
SanjaTronicMotores motores;

void setup() 
{
  motores.definirPinosMotores(16, 15, 17, 14, 7, 11);
  motores.setVelocidadeMotores(60, 75);
}

void loop() 
{
  motores.moverFrente();
  delay(2000);
  motores.parar();
  delay(1000);

  /*motores.moverTras();
  delay(2000);

  motores.virarEsquerda();
  delay(2000);

  motores.virarDireita();
  delay(2000);*/
}
