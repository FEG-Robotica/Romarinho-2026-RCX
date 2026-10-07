#ifndef MOVIMENTO_H
#define MOVIMENTO_H

#include <Arduino.h>
#include "defines.h"

void frente()
{
    analogWrite(IN1, 200);
    analogWrite(IN2, 0);
    analogWrite(IN3, 200);
    analogWrite(IN4, 0);
}

void tras()
{
    analogWrite(IN1, 0);
    analogWrite(IN2, 200);
    analogWrite(IN3, 0);
    analogWrite(IN4, 200);
}

void girarEsq()
{
    analogWrite(IN1, 0);
    analogWrite(IN2, 200);
    analogWrite(IN3, 200);
    analogWrite(IN4, 0);
}

void girarDir()
{
    analogWrite(IN1, 200);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 200);
}

void parar()
{
    analogWrite(IN1, 200);
    analogWrite(IN2, 200);
    analogWrite(IN3, 200);
    analogWrite(IN4, 200);
    delay(20);
    analogWrite(IN1, 0);
    analogWrite(IN2, 0);
    analogWrite(IN3, 0);
    analogWrite(IN4, 0);
}

void busca()
{
    analogWrite(IN1, 200);
    analogWrite(IN2, 0);
    analogWrite(IN3, 120);
    analogWrite(IN4, 0);
}

void abaixar()
{
    for (pos=90;pos>=0;pos--)
    {
        BND1.write(pos);
        delay(20);
    }
    Serial.println("Bandeira abaixada");
    abaixada = true;
}

void levantar()
{
    for (pos=0;pos<=90;pos++)
    {
        BND1.write(pos);
        delay(20);
    }
    Serial.println("Bandeira levantada");
    abaixada = false;
}

#endif