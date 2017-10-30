/*
 * DayNight.cpp
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */
#include <stdlib.h>
#include <avr/eeprom.h>

#include <terminal.h>

#include "DayNight.h"
#include "PWM.h"
#include "AnimationGlow.h"
#include "AnimationFlipFlop.h"
#include "AnimationOnOff.h"

#define SAMPLE_PERIOD 300  //set to be 30 seconds

Animation *animations[] = {
      new AnimationFlipFlop(5, 2),
      new AnimationGlow(20, 0, 0),
      new AnimationOnOff(2),
      new AnimationGlow(5, 0, 200),
      new AnimationFlipFlop(1, 2),
      new AnimationOnOff(1),
      new AnimationFlipFlop(5, 0),
      new AnimationOnOff(5),
      new AnimationGlow(5, 0, 0),
      new AnimationFlipFlop(1, 0),
      new AnimationFlipFlop(10, 0),
      new AnimationGlow(20, 200, 0),
      new AnimationFlipFlop(5, 1),
      new AnimationFlipFlop(2, 0),
      new AnimationOnOff(10),
      new AnimationGlow(10, 0, 0),
      0
};

DayNight::DayNight(cAnalog *light, cInput *flashSwitch) : mLight(light), mSwitch(flashSwitch)
{
   mFlash = false;
   mTick = 1;
   mSwitch->enablePullUp();
   mAnimationIndex = 0;
   mThreshold = getThreshold();
}

void DayNight::run()
{
   if(mFlash)
   {
      animations[mAnimationIndex]->run();
   }

    if(mTick--)
        return;
    mTick = SAMPLE_PERIOD;

    if(!mLight)
        return;

    uint16_t light = mLight->lastSample();
    printp("Light: %d > %d\n", light, mThreshold);
    if(light > mThreshold)
    {
       if(mSwitch->get())
       {
          mFlash = false;
          pwm.setDuty(0, 0xFF);
          pwm.setDuty(1, 0xFF);
       }
       else
       {
          mFlash = true;
          mAnimationIndex++;
          if(animations[mAnimationIndex] == 0)
             mAnimationIndex = 0;
       }
    }
    else
    {
       mFlash = false;
       pwm.setDuty(0, 0);
       pwm.setDuty(1, 0);
    }
}
void DayNight::setThreshold(uint16_t threshold)
{
   mThreshold = threshold;
   eeprom_write_word(0x00, threshold);
}

uint16_t DayNight::getThreshold()
{
   return eeprom_read_word(0x00);
}

DayNight::~DayNight()
{
}
