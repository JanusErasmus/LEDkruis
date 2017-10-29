/*
 * AnimationGlow.cpp
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#include "AnimationGlow.h"
#include "PWM.h"

AnimationGlow::AnimationGlow(uint8_t diff, uint8_t offset1, uint8_t offset2) : glow1(&pwm, 0, diff, offset1),  glow2(&pwm, 1, diff, offset2)
{

}

void AnimationGlow::run()
{
   glow1.run();
   glow2.run();
}

AnimationGlow::~AnimationGlow()
{
}

