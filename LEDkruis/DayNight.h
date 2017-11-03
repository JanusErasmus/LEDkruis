/*
 * DayNight.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef DAYNIGHT_H_
#define DAYNIGHT_H_
#include <avr/io.h>

#include <analog.h>
#include <input.h>

class DayNight
{
   uint8_t mNextOverride;
   uint8_t mFlash;
   uint16_t mTick;
   cAnalog *mLight;
   uint16_t mThreshold;
   cInput *mSwitch;
   uint8_t mAnimationIndex;

public:
   DayNight(cAnalog *light, cInput *flashSwitch);
   virtual ~DayNight();

   void run();
   void next(uint8_t override = false);

   void setThreshold(uint16_t threshold);
   uint16_t getThreshold();
};

#endif /* DAYNIGHT_H_ */
