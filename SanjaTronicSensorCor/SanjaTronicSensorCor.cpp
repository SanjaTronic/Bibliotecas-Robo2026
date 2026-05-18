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

void SanjaTronicSensorCor::leituraCores()
{
  digitalWrite(PinS2, LOW);
  digitalWrite(PinS3, LOW);
  red = pulseIn(PinOUT, LOW);

  Serial.print(" R: ");
  Serial.print(red);

  delay(15);

  digitalWrite(PinS2, HIGH);
  digitalWrite(PinS3, HIGH);
  green = pulseIn(PinOUT, LOW);

  Serial.print(" G: ");
  Serial.print(green);

  delay(15);

  digitalWrite(PinS2, LOW);
  digitalWrite(PinS3, HIGH);
  blue = pulseIn(PinOUT, LOW);

  Serial.print(" B: ");
  Serial.print(blue);

  delay(15);

  cores();

  delay(1000);
}

void SanjaTronicSensorCor::cores()
{
  if (blue < 20 && red < 20 && green < 20) { //detecção da cor branca
    Serial.println("Branco");
  }
  else if ((red > 32 && red < 70) && (green > 31 && green < 60) && (blue > 22 && blue < 38)) { // detecção da cor preta
    Serial.println("PRETO");
    /*
    pararMotores();
    paraTras();
    delay(3000);
    */
  }

  else if((red > 27 && red < 42) && (green > 20 && green < 35) && (blue > 12 && blue < 20)) { // detecção da cor azul
    Serial.println("AZUL");
    /*
    pararMotores();                    
    delay(5000);
    */
  }

  else if (red < blue && red < green && red < 100) { //detecção da cor vermelha
    Serial.println("Vermelho");
    // Lógica da zona de perigo
  }
}