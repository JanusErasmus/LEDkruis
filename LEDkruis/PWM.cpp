/*
 * PWM.cpp
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */
#include <avr/io.h>

#include "PWM.h"

PWM::PWM()
{
   //Setup pins as output
   DDRD |= (1 << 5) | (1 << 6);

   //Setup timer
   TCCR0A = 0x03;   //Setup timer0 in fast PWM for both the pins
   TCCR0B = 0x03;   //Use clkIO/1024
}

void PWM::setDuty(uint8_t port, uint8_t duty)
{
   if(port == 0)
   {
      if(duty)
      {
         TCCR0A |= 0x20;
         OCR0B = duty;
      }
      else
      {
         TCCR0A &= ~(0x30);
      }
   }

   if(port == 1)
   {
      if(duty)
      {
         TCCR0A |= 0x80;
         OCR0A = duty;
      }
      else
      {
         TCCR0A &= ~(0xC0);
      }
   }
}

int8_t PWM::getDuty(uint8_t port)
{
   if(port >= PWM_PORT_COUNT)
      return -1;

   return mDuty[port];
}

PWM::~PWM()
{
   // TODO Auto-generated destructor stub
}

