/*
 * botoes.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: 161855
 */

#ifndef BOTOES_H_
#define BOTOES_H_

#define P     22
#define UP    24
#define DOWN  26
#define S     28

void inicializa_botoes();
void ini_trat_botoes();
void update_botoes();
bool P_button();
bool SetPoint_button();
bool UP_button();
bool DOWN_button();

#endif/* BOTOES_H_ */
