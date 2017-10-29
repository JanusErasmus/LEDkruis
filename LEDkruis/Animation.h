/*
 * Animation.h
 *
 *  Created on: 28 Oct 2017
 *      Author: Janus
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

class Animation
{
public:
   Animation(){};
   virtual ~Animation(){};

   virtual void run() = 0;
};



#endif /* ANIMATION_H_ */
