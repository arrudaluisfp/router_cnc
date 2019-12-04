/*
   serial.cpp

    Created on: 27 de nov de 2019
        Author: 161855
*/
#include "Arduino.h"
#include "telas.h"
#include "motor.h"
#include <string.h>
#include <stdlib.h>

#define FINAL 0
#define S     1
#define CW    2
#define CCW   3
#define F     4
#define X     5
#define Y     6
#define Z     7
#define TAM   8

String comando, f_valor, s_aux, cw_aux, ccw_aux, x_aux, y_aux, z_aux, rapido = "Rapido", medio = "Medio", lento = "Lento";
char recebe, termina = '0', s_valor[4], cw_valor[4], ccw_valor[4], x_valor[4], y_valor[4], z_valor[4];
int posicoes[8], mediano, maximo, minimo, s;


void inicializa_serial()
{
  Serial.begin(9600);
  mediano = maximo = minimo = -1;
}

int ajusta (int atual_posicao, int *posicoes)
{
  int i, proximo;
  for (i = 0; i < TAM; i++)
  {
    if (i == 0)
      proximo = posicoes[i];
    else if (atual_posicao < posicoes[i] && posicoes[i] < proximo)
      proximo = posicoes[i];
  }

  return proximo;
}

void recebe_valor()
{
  int proximo, x_final, y_final;

  recebe = Serial.read();
  comando.concat(recebe);
  if (comando.startsWith("$") && comando.endsWith("#"))
  {
    posicoes[FINAL] = comando.indexOf("#");
    posicoes[S]     = comando.indexOf("S=");
    posicoes[CW]    = comando.indexOf("M3");
    posicoes[CCW]   = comando.indexOf("M4");
    posicoes[F]     = comando.indexOf("F=");
    posicoes[X]     = comando.indexOf("X=");
    posicoes[Y]     = comando.indexOf("Y=");
    posicoes[Z]     = comando.indexOf("Z=");

    Serial.print("COMANDOS SERIAL: ");
    Serial.println(comando);

    if (posicoes[S] > 0)
    {
      proximo = ajusta(posicoes[S], posicoes);
      Serial.print("VALOR DE S: ");
      s_aux = comando.substring(posicoes[S] + 2, proximo + 1);
      s_aux.toCharArray(s_valor, s_aux.length());
      s = atoi(s_valor);
      if(s > 200 && s < 2000)
    	  valor_s = s;
      Serial.println(s);
    }

    if (posicoes[F] > 0)
    {
      proximo = ajusta(posicoes[F], posicoes);
      Serial.print("VALOR DE F: ");
      f_valor = comando.substring(posicoes[F] + 2, proximo);
      Serial.println(f_valor);
      if(rapido.equals(f_valor) == true)
        ajusta_velocidade(MAX);
      else if(medio.equals(f_valor) == true)
        ajusta_velocidade(MED);
      else if(lento.equals(f_valor) == true)
        ajusta_velocidade(MIN);
    }

    if (posicoes[X] > 0)
    {
      proximo = ajusta(posicoes[X], posicoes);
      Serial.print("VALOR DE X: ");
      x_aux = comando.substring(posicoes[X] + 2, proximo + 1);
      x_aux.toCharArray(x_valor, x_aux.length());
      x_final = atoi(x_valor);
      Serial.println(x_final);
    }

    if (posicoes[Y] > 0)
    {
      proximo = ajusta(posicoes[Y], posicoes);
      Serial.print("VALOR DE Y: ");
      y_aux = comando.substring(posicoes[Y] + 2, proximo + 1);
      y_aux.toCharArray(y_valor, y_aux.length());
      y_final = atoi(y_valor);
      Serial.println(y_final);
    }

    if (posicoes[Z] > 0)
    {
      proximo = ajusta(posicoes[Z], posicoes);
      Serial.print("VALOR DE Z: ");
      z_aux = comando.substring(posicoes[Z] + 2, proximo + 1);
      z_aux.toCharArray(z_valor, z_aux.length());
      valor_z = atoi(z_valor);
      Serial.println(valor_z);
    }
    if (posicoes[CW] > 0)
    {
      Serial.println("ROTACAO SENTIDO CW: M3");
    }
    if (posicoes[CCW] > 0)
    {
      Serial.println("ROTACAO SENTIDO CCW: M4");
    }
    comando = "\0";

    if(x_final > 0 && y_final > 0)
    	interpolacao(valor_x, valor_y, x_final, y_final);
  }
}
