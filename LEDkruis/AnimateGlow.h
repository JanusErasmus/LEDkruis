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
   uint8_t mCurrentDiff;
   uint8_t mDuty;

public:
   AnimateGlow(PWM *pwm, uint8_t port, uint8_t diff);
   virtual ~AnimateGlow();

   void run();
};

#endif /* ANIMATEGLOW_H_ */
