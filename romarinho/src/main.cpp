#include <Arduino.h>
#include <Servo.h>
#include <Arduino_FreeRTOS.h>
#include "movimento.h"
#include "defines.h"

int limiteLinha = 1000; //branco < limite, preto > limite (verificar)
bool ativo = false;

void setup()
{
  Serial.begin(9600);

  pinMode(linhaEsq, INPUT);
  pinMode(linhaDir, INPUT);

  pinMode(SLD, INPUT);
  pinMode(SFD, INPUT);
  pinMode(SM, INPUT);
  pinMode(SFE, INPUT);
  pinMode(SLE, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SIN, INPUT_PULLUP); //arduino nano n tem pulldown interno

  //servo
  BND1.attach(band);
}

String bufferComando = "";

void loop()
{
  // analogWrite(IN1,0);
  // analogWrite(IN2,1023);
  // analogWrite(IN3,0);
  // analogWrite(IN4,1023);

   if (digitalRead(SIN) == 0)  //lógica invertida
   {
     //ler sensores
     int linhaE = analogRead(linhaEsq);
     int linhaD = analogRead(linhaDir);

     int sld = digitalRead(SLD);
     int sfd = digitalRead(SFD);
     int sfe = digitalRead(SFE);
     int sle = digitalRead(SLE);

     //linha
     if (linhaE < limiteLinha)
     {
       tras();
       delay(20);
       girarDir();
       delay(20);
       return;
     }
     else if (linhaD < limiteLinha)
     {
       tras();
       delay(20);
       girarEsq();
       delay(20);
       return;
     }

     //ataque
     //1 detectou, 0 não detectou (verificar)
     if (sfe == 1 && sfd == 1)
     {
       frente();
     }
     else if (sld == 1)
     {
       girarDir();
     }
     else if (sle == 1) 
     {
       girarEsq();
     }
     else 
     {
       busca(); //procurar
     }
   }
   else
   {
     parar();
   }
}