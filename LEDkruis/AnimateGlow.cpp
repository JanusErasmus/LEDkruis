/*
 * AnimateGlow.cpp
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */

#include "AnimateGlow.h"

AnimateGlow::AnimateGlow(PWM *pwm, uint8_t port, uint8_t diff) :
         mPWM(pwm),
         mPort(port),
         mDiff(diff),
         mCurrentDiff(diff),
         mDuty(0)
{

}

void AnimateGlow::run()
{
   mDuty += mCurrentDiff;
   if(mDuty >= 250)
      mCurrentDiff = -mDiff;

   if(mDuty == 0)
      mCurrentDiff = mDiff;

   mPWM->setDuty(mPort, mDuty);
}

AnimateGlow::~AnimateGlow()
{
}

