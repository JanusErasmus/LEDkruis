/*
 * AnimationOnOff.cpp
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#include "AnimationOnOff.h"
#include "PWM.h"

AnimationOnOff::AnimationOnOff(uint8_t count)
{
   mTick = 0;
   mCount = count;
   mOnFlag = 0;
}

void AnimationOnOff::run()
{
   if(mTick--)
      return;

   mTick = mCount;

   if(mOnFlag)
   {
      mOnFlag = 0;
      pwm.setDuty(0, 0xFF);
      pwm.setDuty(1, 0xFF);
   }
   else
   {
      mOnFlag = 1;
      pwm.setDuty(0, 0x00);
      pwm.setDuty(1, 0x00);
   }

}

AnimationOnOff::~AnimationOnOff()
{
}

