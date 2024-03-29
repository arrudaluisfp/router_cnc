/*
 * botoes.cpp
 *
 *  Created on: 20 de nov de 2019
 *      Author: 161855
 */
#include "botoes.h"
#include "Bounce2.h"

Bounce SetPoint_BOTAO = Bounce();
Bounce P_BOTAO        = Bounce();
Bounce UP_BOTAO       = Bounce();
Bounce DOWN_BOTAO     = Bounce();

void inicializa_botoes()
{
  pinMode(P,    INPUT_PULLUP);
  pinMode(UP,   INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(S,    INPUT_PULLUP);
}

void ini_trat_botoes()
{
  SetPoint_BOTAO.attach(S);
  P_BOTAO.attach(P);
  UP_BOTAO.attach(UP);
  DOWN_BOTAO.attach(DOWN);
  SetPoint_BOTAO.interval(25);
  P_BOTAO.interval(25);
  UP_BOTAO.interval(25);
  DOWN_BOTAO.interval(25);
}

void update_botoes()
{
  SetPoint_BOTAO.update();
  P_BOTAO.update();
  UP_BOTAO.update();
  DOWN_BOTAO.update();
}

bool P_button()
{
  if (P_BOTAO.fell())
    return true;
  else
    return false;
}

bool SetPoint_button()
{
  if (SetPoint_BOTAO.fell())
    return true;
  else
    return false;
}

bool UP_button()
{
  if (UP_BOTAO.fell())
    return true;
  else
    return false;
}

bool DOWN_button()
{
  if (DOWN_BOTAO.fell())
    return true;
  else
    return false;
}
