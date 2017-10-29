/*
 * AnimationGlow.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef ANIMATIONGLOW_H_
#define ANIMATIONGLOW_H_

#include "Animation.h"
#include "AnimateGlow.h"

class AnimationGlow : public Animation
{
   AnimateGlow glow1;
   AnimateGlow glow2;

public:
   AnimationGlow(uint8_t diff, uint8_t offset1, uint8_t offset2);
   virtual ~AnimationGlow();

   void run();
};

#endif /* ANIMATIONGLOW_H_ */
