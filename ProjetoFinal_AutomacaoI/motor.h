#ifndef MOTOR_H_
#define MOTOR_H_

#define MAX 	360
#define MIN 	 90
#define MED 	180
#define PWM_MAX 255
#define FA	    5.0
#define ENC_PPR  20
#define PWM_MIN  60
#define K_RPM   MIN*FA/ENC_PPR
#define TA      1/FA*1000
#define TEMP    1000
#define PULSO    40

void inicializa_motor();
void comanda_motor();
void incrementa_x(int passo);
void decrementa_x(int passo);
void incrementa_y(int passo);
void decrementa_y(int passo);
void incrementa_z(int passo);
void decrementa_z(int passo);
void serial_s(int serials);
void manual_s(int manuals);
void spindle();
void ajusta_velocidade(int velocidade);
void interpolacao(int x0, int y0, int xf, int yf);

#endif
