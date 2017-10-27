/*
 * PWM.h
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */

#ifndef PWM_H_
#define PWM_H_

/** PWM for the LEDkruis
 * Uses TIMER0 to toggle pins PD5 and PD6 (aka TIMER0 OCMA and OCMB)
 */
class PWM
{
public:
   PWM();
   virtual ~PWM();
};

#endif /* PWM_H_ */
