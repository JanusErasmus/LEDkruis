/*
 * AnimationOnOff.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef ANIMATIONONOFF_H_
#define ANIMATIONONOFF_H_
#include "Animation.h"
#include <avr/io.h>

class AnimationOnOff : public Animation
{
   uint8_t mTick;
   uint8_t mCount;
   uint8_t mOnFlag;

public:
   AnimationOnOff(uint8_t count);
   virtual ~AnimationOnOff();

   void run();
};

#endif /* ANIMATIONONOFF_H_ */
