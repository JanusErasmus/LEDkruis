/*
 * PWM.cpp
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */
#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>

#include <terminal.h>

#include "PWM.h"

PWM::PWM()
{

   //Setup timer
   TCCR0A = 0x03;   //Setup timer0 in fast PWM for both the pins
   TCCR0B = 0x03;   //Use clkIO/1024
}

void PWM::setDuty(uint8_t port, uint8_t duty)
{
   if(port == 0)
   {
      mDuty[port] = duty;
      if(duty)
      {
         //Setup pins as output
         DDRD |= (1 << 5);
         TCCR0A |= 0x30;
         OCR0B = duty;
      }
      else
      {
         //Setup pins as input
         DDRD &= ~(1 << 5);
         TCCR0A &= ~(0x30);
      }
   }

   if(port == 1)
   {
      //Setup pins as output
      DDRD |= (1 << 6);
      mDuty[port] = duty;
      if(duty)
      {
         TCCR0A |= 0xC0;
         OCR0A = duty;
      }
      else
      {
         //Setup pins as input
         DDRD &= ~(1 << 6);
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

PWM pwm;

void debugPWM(uint8_t argc, char **argv)
{
   if(argc > 2)
   {
      uint8_t port = atoi(argv[1]);
      uint8_t duty = atoi(argv[2]);

      printp("Set %d to %d\n", port, duty);
      pwm.setDuty(port, duty);
   }
   else
   {
      printp("Port 0: %d\n", (uint8_t)pwm.getDuty(0));
      printp("Port 1: %d\n", (uint8_t)pwm.getDuty(1));
   }
}
extern const dbg_entry outputEntry = {debugPWM, "pwm"};
