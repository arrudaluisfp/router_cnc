/*
 * telas.h
 *
 *  Created on: 20 de nov de 2019
 *      Author: 161855
 */

#ifndef TELAS_H_
#define TELAS_H_
#define CLOSED 18

typedef enum
{
  INICIAL = 0, ERRO, REFERENCIAMENTO, POSICAO, MOVIMENTACAO, OVERTRAVEL
} Estados;

typedef enum
{
  LIMITE_MAXZ = 1, LIMITE_MINZ, LIMITE_MAXX, LIMITE_MINX, LIMITE_MAXY, LIMITE_MINY
} OverTravel;

extern int estado, overTravel, valor_s, valor_x, valor_y, valor_z;

void inicializa_tela();
void interrupcao();
void inicial();
void referenciamento();
void inicial();
void posicao();
void movimentacao();
void overtravel();
void funcao_principal();


#endif /* TELAS_H_ */
