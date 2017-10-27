/*
 * PWM.h
 *
 *  Created on: 27 Oct 2017
 *      Author: Janus
 */

#ifndef PWM_H_
#define PWM_H_

#define PWM_PORT_COUNT 2

/** PWM for the LEDkruis
 * Uses TIMER0 to toggle pins PD5 and PD6 (aka TIMER0 OCMA and OCMB)
 */
class PWM
{
   uint8_t mDuty[PWM_PORT_COUNT];

public:
   PWM();
   virtual ~PWM();

   void setDuty(uint8_t port, uint8_t duty);
   int8_t getDuty(uint8_t port);
};

extern PWM pwm;
#endif /* PWM_H_ */
