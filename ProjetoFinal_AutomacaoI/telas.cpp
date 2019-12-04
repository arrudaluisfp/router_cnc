/*
   telas.cpp

    Created on: 20 de nov de 2019
        Author: 161855
*/
#include "Arduino.h"
#include "telas.h"
#include "heart_beat.h"
#include "botoes.h"
#include "motor.h"
#include "serial.h"
#include <Bounce2.h>
#include <LiquidCrystal.h>

#define CLOSED 18

int estado = INICIAL, valor_s, valor_x, valor_y, valor_z, overTravel = 0;
const long intervalo = 600;
unsigned long currentMillis;

LiquidCrystal lcd(31, 33, 35, 37, 39, 41); // @suppress("Abstract class cannot be instantiated")

void interrupcao()
{
  if (estado != INICIAL)
    estado = ERRO;
}

void inicializa_tela()
{
  lcd.begin(16, 2);
  pinMode(HEART_BEAT, OUTPUT);
  pinMode(CLOSED    ,  INPUT);
  digitalWrite(A0, HIGH);
  attachInterrupt(digitalPinToInterrupt(CLOSED), interrupcao, LOW);
}

void inicial()
{
  lcd.clear();
  while (estado == INICIAL)
  {
    update_botoes();
    heart_beating();
    lcd.setCursor(3, 0);
    lcd.print("CNC Router");
    lcd.setCursor(0, 1);
    lcd.print("Home Ret? <S>");
    if (SetPoint_button())
    {
      if (digitalRead(CLOSED) == LOW)
        estado = ERRO;
      else
        estado = REFERENCIAMENTO;
    }
  }
}

void erro()
{
  lcd.clear();
  currentMillis = millis();
  while (estado == ERRO)
  {
    heart_beating();
    lcd.setCursor(0, 0);
    lcd.print("Erro: Please");
    lcd.setCursor(0, 1);
    lcd.print("Close the Cover!");
    if (currentMillis + intervalo <= millis())
      estado = INICIAL;
  }
}

void referenciamento()
{
  lcd.clear();
  while (estado == REFERENCIAMENTO)
  {
    heart_beating();
    lcd.setCursor(0, 0);
    lcd.print("Machine Home");
    lcd.setCursor(0, 1);
    lcd.print("in progress...");
    comanda_motor();
    estado = POSICAO;
    valor_s = valor_x = valor_y = valor_z = 0;
  }
}

void posicao()
{
	lcd.clear();
	int s = 0;
  while (estado == POSICAO)
  {
    update_botoes();

    if (Serial.available() > 0)
    {
    	recebe_valor();
    }

    if (SetPoint_button())
    {
    	if(s == 0)
    	{
    		serial_s(valor_s);
    	}
    	else
    	{
    		s = 0;
    		serial_s(0);
    	}
    }

    lcd.setCursor(0, 0);
    lcd.print("*S: ");
    lcd.print(valor_s);

    lcd.setCursor(10, 0);
    lcd.print("Z: ");
    lcd.print(valor_z);

    lcd.setCursor(0, 1);
    lcd.print("X:    ");
    lcd.print(valor_x);

    lcd.setCursor(10, 1);
    lcd.print("Y: ");
    lcd.print(valor_y);

    if (P_button())
    	estado = MOVIMENTACAO;

  }
}

void movimentacao()
{
  lcd.clear();
  int aux = 0, aux1 = 0, aux2 = 0;
  valor_s = 0;
  while (estado == MOVIMENTACAO)
  {
	  update_botoes();
    if (aux1 == 0)
    {
      lcd.setCursor(0, 0);
      lcd.print("S:    ");
      lcd.print(valor_s);

      lcd.setCursor(10, 0);
      lcd.print("Z: ");
      lcd.print(valor_z);

      lcd.setCursor(0, 1);
      lcd.print("X:    ");
      lcd.print(valor_x);

      lcd.setCursor(10, 1);
      lcd.print("Y: ");
      lcd.print(valor_y);
    }

    if (SetPoint_button())
    {
    	if(valor_s == 0)
		{
    		valor_s = 500;
			manual_s(valor_s);
		}
		else
		{
			valor_s = 0;
			manual_s(valor_s);
		}
    }

    if (aux == 0)
    	lcd.noCursor();

    if (P_button()) aux = 1;

    while (aux == 1) //Z
    {
      update_botoes();
      if (estado == ERRO)
      {
        lcd.noCursor();
        break;
      }
      if (aux2 == 0)
      {
        lcd.setCursor(10, 0);
        lcd.cursor();
      }

      if (P_button())
      {
        aux2++;
        aux = 2; break;
      }
      if (UP_button())
      {
        valor_z++;
        if (valor_z > 150)
        {
          valor_z = 150;
          aux = 0;
          overTravel = 1;
          estado = OVERTRAVEL;
        }
        if (valor_z < 150)
          incrementa_z(10);

        lcd.setCursor(13, 0);
        lcd.print(valor_z);
      }
      if (DOWN_button())
      {
        valor_z--;
        if (valor_z <= -1)
        {
          valor_z = 0;
          overTravel = 2;
          lcd.clear();
          aux = 0;
          estado = OVERTRAVEL;
        }
        if (valor_z > 0)
          decrementa_z(10);

        lcd.setCursor(13, 0);
        lcd.print(valor_z);
      }
    }

    while (aux == 2) //X
    {
      update_botoes();
      if (estado == ERRO)
      {
        lcd.noCursor();
        break;
      }
      if (aux2 == 1)
      {
        lcd.setCursor(0, 1);
        lcd.cursor();
      }

      if (P_button())
      {
        aux2++;
        aux = 3; break;
      }
      if (UP_button())
      {
        valor_x++;
        if (valor_x > 200)
        {
          valor_x = 200;
          aux = 0;
          overTravel = 3;
          estado = OVERTRAVEL;
        }
        if (valor_x < 200)
          incrementa_x(10);

        lcd.setCursor(6, 1);
        lcd.print(valor_x);
      }
      if (DOWN_button())
      {
        valor_x--;
        if (valor_x <= -1)
        {
          valor_x = 0;
          aux = 0;
          overTravel = 4;
          estado = OVERTRAVEL;
        }
        if (valor_x > 0)
          decrementa_x(10);

        lcd.setCursor(6, 1);
        lcd.print(valor_x);
      }
    }

    while (aux == 3) //Y
    {
      update_botoes();
      if (estado == ERRO)
      {
        lcd.noCursor();
        break;
      }
      if (aux2 == 2)
      {
        lcd.setCursor(10, 1);
        lcd.cursor();
      }
      if (P_button())
      {
    	  estado = POSICAO;
    	  lcd.noCursor();
        aux2 = 0;
        aux = 0; break;
      }
      if (UP_button())
      {
        valor_y++;

        if (valor_y > 300)
        {
          valor_y = 300;
          aux = 0;
          overTravel = 5;
          estado = OVERTRAVEL;
        }
        if (valor_y < 300)
          incrementa_y(10);

        lcd.setCursor(13, 1);
        lcd.print(valor_y);
      }
      if (DOWN_button())
      {
        valor_y--;
        if (valor_y <= -1) {
          valor_y = 0;
          aux = 0;
          overTravel = 6;
          estado = OVERTRAVEL;
        }
        if (valor_y > 0)
          decrementa_y(10);

        lcd.setCursor(13, 1);
        lcd.print(valor_y);
      }
    }
  }
}

void overtravel()
{
  lcd.clear();
  currentMillis = millis();
  while (estado == OVERTRAVEL)
  {
    update_botoes();
    lcd.setCursor(2, 0);
    lcd.print("Over  Travel");
    lcd.setCursor(4, 1);
    lcd.print("Axis: ");
    switch (overTravel)
    {
      case LIMITE_MINX:
        lcd.print("X-");
        break;
      case LIMITE_MAXX:
        lcd.print("X+");
        break;
      case LIMITE_MINY:
        lcd.print("Y-");
        break;
      case LIMITE_MAXY:
        lcd.print("Y+");
        break;
      case LIMITE_MINZ:
        lcd.print("Z-");
        break;
      case LIMITE_MAXZ:
        lcd.print("Z+");
        break;
    }
    lcd.noCursor();
    if (currentMillis + intervalo <= millis())
      estado = POSICAO;
  }
}


void funcao_principal()
{
  switch (estado)
  {
    case INICIAL:
      inicial();
      break;

    case ERRO:
      erro();
      break;

    case REFERENCIAMENTO:
      referenciamento();
      break;

    case POSICAO:
      posicao();
      break;

    case MOVIMENTACAO:
      movimentacao();
      break;

    case OVERTRAVEL:
      overtravel();
      break;
  }
}



