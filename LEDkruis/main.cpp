#include <stdio.h>
#include <float.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>

#include <terminal.h>
#include <led.h>
#include <heartbeat.h>
#include <analog_sampler.h>
#include <input.h>

#include "PWM.h"
#include "AnimateGlow.h"
#include "DayNight.h"

void watchdogReset()
{
  __asm__ __volatile__ ( "wdr\n" );
}


cAnalog light(6);

void sample(uint8_t argc, char **argv)
{
    printp("Measuring temp:\n");

    double sample = light.lastSample();
    printf(" 1: %.1f\n", sample);

}
extern const dbg_entry analogEntry = {sample, "a"};

cInput flashSwitch(0x24);
DayNight dayNight(&light, &flashSwitch);

void debugDN(uint8_t argc, char **argv)
{
   if(argc > 1)
   {
      uint16_t th = atoi(argv[1]);

      printp("Set threshold %d\n", th);
      dayNight.setThreshold(th);
   }
   else
   {
      printp("Threshold: %d\n", dayNight.getThreshold());
   }
}
extern const dbg_entry thEntry = {debugDN, "th"};

cOutput statusGreen(0x15);

/* main program starts here */
int main(void)
{
	//WDTCSR = _BV(WDCE) | _BV(WDE);
	//WDTCSR = (_BV(WDP2) | _BV(WDP1) | _BV(WDP0) | _BV(WDE));

	sei();

	cLED status(0, &statusGreen);
	cHeartbeat heartbeat(&status);

    cAnalog *analogList[] =
    {
            &light,
            0
    };
    cAnalogSampler analogSampler(analogList);


    printp("Light threshold: %d\n", dayNight.getThreshold());

	while(1)
	{
		watchdogReset();

		Terminal.run();
		heartbeat.run();
		analogSampler.run();
		dayNight.run();

		_delay_ms(100);
	}

	return 0;
}

