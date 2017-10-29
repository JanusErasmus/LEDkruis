/*
 * AnimationFlipFlop.cpp
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#include "AnimationFlipFlop.h"
#include "PWM.h"

AnimationFlipFlop::AnimationFlipFlop(uint8_t period, uint8_t count)
{
   mPeriod = period;
   mTick = 0;
   mFlipFlag = 0;
   mCount = count;
   mCounter = count;
}

void AnimationFlipFlop::run()
{
   if(mTick--)
      return;

   mTick = mPeriod;

   switch(mFlipFlag)
   {
   case 0:
      mFlipFlag = 1;
      pwm.setDuty(0, 0xFF);
      pwm.setDuty(1, 0x00);
      break;
   case 1:
      if(mCounter--)
      {
         mFlipFlag = 0;
      }
      else
      {
         mFlipFlag = 2;
         mCounter = mCount;
      }

      pwm.setDuty(0, 0x00);
      pwm.setDuty(1, 0x00);
      break;
   case 2:
      mFlipFlag = 3;
      pwm.setDuty(0, 0x00);
      pwm.setDuty(1, 0xFF);
      break;
   case 3:
      if(mCounter--)
      {
         mFlipFlag = 2;
      }
      else
      {
         mFlipFlag = 0;
         mCounter = mCount;
      }
      pwm.setDuty(0, 0x00);
      pwm.setDuty(1, 0x00);
      break;
   }
}

AnimationFlipFlop::~AnimationFlipFlop()
{
}

