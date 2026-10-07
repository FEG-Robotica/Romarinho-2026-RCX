#ifndef DEFINES_H
#define DEFINES_H

#include <Servo.h>

// sensores de linha
#define linhaEsq A1
#define linhaDir A2

// sensores de distância
#define SLD 21
#define SFD 20
#define SM 19
#define SFE 18
#define SLE 17

// motores
#define IN1 10
#define IN2 9
#define IN3 6
#define IN4 5

// bandeira
Servo BND1;
int band = 3; //pino da bandeira
int pos;
bool abaixada = false;

// modulo start
#define SIN 4

#endif