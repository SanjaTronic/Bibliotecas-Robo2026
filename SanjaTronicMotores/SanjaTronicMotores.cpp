#include "SanjaTronicMotores.h"

void SanjaTronicMotores::definirPinosMotores(int in1, int in2, int in3, int in4, int ena, int enb)
{
  this->in1 = in1;
  this->in2 = in2;
  this->in3 = in3;
  this->in4 = in4;
  this->ena = ena;
  this->enb = enb;

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}

void SanjaTronicMotores::setVelocidadeMotores(int velocidadeE, int velocidadeD)
{
  this->velocidadeE = velocidadeE;
  this->velocidadeD = velocidadeD;
}

void SanjaTronicMotores::configurarMotores(int velocidadeE, int velocidadeD, bool ligDesM1, bool ligDesM2, bool ligDesM3, bool ligDesM4)
{
  analogWrite(ena, velocidadeE);
  analogWrite(enb, velocidadeD);

  digitalWrite(in1, ligDesM1);
  digitalWrite(in2, ligDesM2);
  digitalWrite(in3, ligDesM3);
  digitalWrite(in4, ligDesM4);
}

void SanjaTronicMotores::moverFrente()
{ 
  configurarMotores(this->velocidadeE, this->velocidadeD, 0, 1, 0, 1);
}

void SanjaTronicMotores::moverTras()
{
  configurarMotores(this->velocidadeE, this->velocidadeD, 1, 0, 1, 0);
}

void SanjaTronicMotores::virarEsquerda()
{
  configurarMotores(velocidadeCurvaEsq, velocidadeCurvaDir, 0, 1, 1, 0); // 0, 1, 1, 0
}

void SanjaTronicMotores::virarDireita()
{
  configurarMotores(velocidadeCurvaEsq, velocidadeCurvaDir, 1, 0, 0, 1); // 1, 0, 0, 1
}

void SanjaTronicMotores::parar()
{
  configurarMotores(0, 0, 0, 0, 0, 0);
}
