/*
 * heart_beat.cpp
 *
 *  Created on: 20 de nov de 2019
 *      Author: 161855
 */
#include "Arduino.h"
#include "heart_beat.h"
//#include "controles.h"

void heart_beating()
{
  static unsigned long long int millis_heartbeat = 0;

  if (digitalRead(A0) == HIGH)
  {
    if (millis() - millis_heartbeat >= DELAY_HEARTBEAT)
    {
      millis_heartbeat = millis();
      digitalWrite(HEART_BEAT, !digitalRead(HEART_BEAT));
    }
  }
  else if (digitalRead(A0) == LOW)
    digitalWrite(HEART_BEAT, HIGH);
}
// A0 como o pino do ENABLE

