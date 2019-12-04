/*
 * motor.cpp
 *
 *  Created on: 4 de dez de 2019
 *      Author: 161855
 */
#include <Stepper.h>
#include "motor.h"
#include "arduino.h"
#include "heart_beat.h"
#include "telas.h"

int SPINDLE = 44;
const int passos = 10;  // passos por volta
bool flag_x, flag_y, flag_z;

// Pinos utilizados para a comunicacao
// (8 e 9 de um lado, 10 e 11 do outro)
Stepper posicao_x(passos,  2,  3,  4,  5);
Stepper posicao_y(passos,  6,  7,  8,  9);
Stepper posicao_z(passos, 10, 11, 12, 13);

void inicializa_motor()
{
  posicao_x.setSpeed(MIN);
  posicao_y.setSpeed(MIN);
  posicao_z.setSpeed(MIN);
  flag_x = false, flag_y = false, flag_z = false;
}

void comanda_motor()
{
  while (!(flag_x == true && flag_y == true && flag_z == true))
  {
    heart_beating();
    if (digitalRead(19) == LOW)
      posicao_x.step(-passos);
    else
      flag_x = true;
    if (digitalRead(20) == LOW)
      posicao_y.step(-passos);
    else
      flag_y = true;
    if (digitalRead(21) == LOW)
      posicao_z.step(-passos);
    else
      flag_z = true;
  }
}

void spindle()
{
	pinMode(SPINDLE, OUTPUT);
	analogWrite(SPINDLE, 0);
}


void ajusta_velocidade(int velocidade)
{
  switch (velocidade)
  {
    case MAX:
      posicao_x.setSpeed(MAX);
      posicao_y.setSpeed(MAX);
      posicao_z.setSpeed(MAX);
      break;
    case MED:
      posicao_x.setSpeed(MED);
      posicao_y.setSpeed(MED);
      posicao_z.setSpeed(MED);
      break;
    case MIN:
      posicao_x.setSpeed(MIN);
      posicao_y.setSpeed(MIN);
      posicao_z.setSpeed(MIN);
      break;
  }
}

void serial_s(int serials)
{
	if(serials != 0)
		serials = map(serials, 200, 2000, 0, 255);

	analogWrite(SPINDLE, serials);
}

void manual_s(int manuals)
{
	if(manuals != 0)
		manuals = map(manuals, 0, 500, 0, 255);

	analogWrite(SPINDLE, manuals);
}

void incrementa_x(int passo)
{
  posicao_x.step(passo);
}

void decrementa_x(int passo)
{
  posicao_x.step(-passo);
}

void incrementa_y(int passo)
{
  posicao_y.step(passo);
}

void decrementa_y(int passo)
{
  posicao_x.step(passo);
}

void incrementa_z(int passo)
{
  posicao_z.step(passo);
}

void decrementa_z(int passo)
{
  posicao_z.step(-passo);
}

void interpolacao(int x0, int y0, int xf, int yf)
{
	int posX = 0, posY = 0, i = 0, maior = 0;

	if(xf > yf)
	{
		Serial.println("X maior que Y ");
		posX = (xf - x0)/(yf - y0);
		posY = (xf - x0)%(yf - y0);
		if(posY == 0)
		{
			incrementa_y(10*(yf - y0));
			valor_y += (yf - y0);

		}
		maior = 1;
		//posX++;
		Serial.println(posX);
		Serial.println(posY);
	}
	else if(yf > xf)
	{
		posY = (yf - y0)/(xf - x0);
		posX = (yf - y0)%(xf - x0);
		if(posX == 0)
		{
			incrementa_x(10*(xf - x0));
			valor_x += (xf - x0);

		}
		maior = 2;

		//posY++;
	}

	while((valor_y != yf) && (valor_x != xf))
	{

		if(valor_x <= xf)
		{
			for(i=0; i<posX; i++)
			{
				incrementa_x(10);
				valor_x+=1;

				Serial.print("X: ");
				Serial.println(valor_x);

			}
		}

		if(valor_y <= yf)
		{
			for(i=0; i<posY; i++)
			{
				incrementa_y(10);
				valor_y+=1;

				Serial.print("Y: ");
				Serial.println(valor_y);
			}
		}
	}

	if(maior == 1)
	{
		if(valor_y == yf)
		{
			incrementa_x(10*posY);
			valor_x += posY;
			Serial.print("X: ");
			Serial.println(valor_x);
		}
	}
	else if(maior == 2)
	{
		if(valor_x == xf)
		{
			incrementa_y(10*posX);
			valor_y += posX;
			Serial.print("Y: ");
			Serial.println(valor_y);
		}
	}

}

