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
   TCCR0A = 0xA3;   //Setup timer0 in fast PWM for both the pins
   TCCR0B = 0x05;   //Use clkIO/1024
   OCR0A = 0x00;    //start with 50%
   OCR0B = 0x7F;    //start with 50%

}

PWM::~PWM()
{
   // TODO Auto-generated destructor stub
}

