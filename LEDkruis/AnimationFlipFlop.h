/*
 * AnimationFlipFlop.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef ANIMATIONFLIPFLOP_H_
#define ANIMATIONFLIPFLOP_H_
#include "Animation.h"
#include <avr/io.h>

class AnimationFlipFlop : public Animation
{
   uint8_t mTick;
   uint8_t mFlipFlag;
   uint8_t mPeriod;
   uint8_t mCount;
   uint8_t mCounter;

public:
   AnimationFlipFlop(uint8_t period, uint8_t count);
   virtual ~AnimationFlipFlop();

   void run();
};

#endif /* ANIMATIONFLIPFLOP_H_ */
