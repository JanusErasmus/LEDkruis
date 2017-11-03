/*
 * PWM.cpp
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>

#include <terminal.h>

#include "PWM.h"


uint8_t mDuty[PWM_PORT_COUNT];
uint8_t mCurrentDuty[PWM_PORT_COUNT];

PWM::PWM()
{
   mCurrentDuty[0] = 0;
   mCurrentDuty[1] = 0;
   mDuty[0] = 0;
   mDuty[1] = 0;

   //Setup timer
   TCCR0A = 0x03;   //Setup timer0 in fast PWM for both the pins
   TCCR0B = 0x05;   //Use clkIO/1024

   //Setup pins as output
   DDRD |= ((1 << 5) | (1 << 6));

   setDuty(0, 0);
   setDuty(1, 0);

}

void PWM::setDuty(uint8_t port, uint8_t duty)
{
   if(port == 0)
   {
      mDuty[port] = duty;
      if(duty)
      {
         TCCR0A |= 0x30;

         if(duty == 255)
         {
            OCR0B = 255;
            mCurrentDuty[0] = 255;
         }
      }
      else
      {
         TCCR0A &= ~(0x30);
         OCR0B = 0;
         PORTD |= (1 << 5);
      }
   }

   if(port == 1)
   {
      mDuty[port] = duty;
      if(duty)
      {
         TCCR0A |= 0xC0;

         if(duty == 255)
         {
            mCurrentDuty[1] = 255;
            OCR0A = 255;
         }
      }
      else
      {
         TCCR0A &= ~(0xC0);
         OCR0A = 0;
         PORTD |= (1 << 6);
      }
   }

   if(mDuty[0] || mDuty[1])
   {
      TIMSK0 = 0x01;
   }
   else
   {
      TIMSK0 = 0x00;
   }
}

int8_t PWM::getDuty(uint8_t port)
{
   if(port >= PWM_PORT_COUNT)
      return -1;

   return mDuty[port];
}

uint8_t followPWM(uint8_t duty, uint8_t current)
{
   if(duty == 255)
   {
      return 255;
   }

   if(current > duty)
   {
      if(current < 5)
         current = 0;
      else
         current -= 5;
   }
   else if(current < duty)
   {
      if(current > 250)
         current = 255;
      else
         current += 5;
   }

   return current;
}

#if defined(__AVR_ATmega328P__)
ISR(TIMER0_OVF_vect)
{
   TIFR0 = 0;

   if(mCurrentDuty[0] != mDuty[0])
   {
      mCurrentDuty[0] = followPWM(mDuty[0], mCurrentDuty[0]);
      OCR0B = mCurrentDuty[0];
   }


   if(mCurrentDuty[1] != mDuty[1])
   {
      mCurrentDuty[1] = followPWM(mDuty[1], mCurrentDuty[1]);
      OCR0A = mCurrentDuty[1];
   }
}
#endif

PWM::~PWM()
{
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
