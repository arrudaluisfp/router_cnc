#include "Arduino.h"
#include "telas.h"
#include "heart_beat.h"
#include "botoes.h"
#include "motor.h"
#include "serial.h"

void setup()
{
	spindle();
	inicializa_botoes();
	inicializa_serial();
	ini_trat_botoes();
	inicializa_tela();
	inicializa_motor();
}

void loop()
{
	funcao_principal();
}
