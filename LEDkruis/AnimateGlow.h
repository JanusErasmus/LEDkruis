/*
 * AnimateGlow.h
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */

#ifndef ANIMATEGLOW_H_
#define ANIMATEGLOW_H_
#include <avr/io.h>

#include "PWM.h"

class AnimateGlow
{
   PWM *mPWM;
   uint8_t mPort;
   uint8_t mDiff;
   int8_t mCurrentDiff;
   int16_t mDuty;

public:
   AnimateGlow(PWM *pwm, uint8_t port, uint8_t diff, uint8_t offset);
   virtual ~AnimateGlow();

   void run();
};

#endif /* ANIMATEGLOW_H_ */
