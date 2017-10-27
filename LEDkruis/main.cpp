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
#include <lcd.h>

void watchdogReset()
{
  __asm__ __volatile__ ( "wdr\n" );
}

//cOutput relay1(PORT_PF(0));
//cOutput relay2(PORT_PF(1));
//cOutput relay3(PORT_PF(2));
//cOutput relay4(PORT_PF(3));
//void debugOut(uint8_t argc, char **argv)
//{
//	cOutput *relay = 0;
//	if(argc > 1)
//	{
//		uint8_t num = atoi(argv[1]);
//		switch(num)
//		{
//		case 1:
//			relay = &relay1;
//			break;
//		case 2:
//			relay = &relay2;
//			break;
//		case 3:
//			relay = &relay3;
//			break;
//		case 4:
//			relay = &relay4;
//			break;
//		default:
//			return;
//		}
//
//		if(argc > 2)
//		{
//			bool state = atoi(argv[2]);
//			printp("%s - ", state?"set":"reset", num);
//			if(state)
//				relay->set();
//			else
//				relay->reset();
//		}
//
//		bool state = relay->get();
//		printp("RL%d: %s\n", num, state?"ON":"OFF");
//	}
//	else
//	{
//		printp("RL1: %s\n", relay1.get()?"ON":"OFF");
//		printp("RL2: %s\n", relay2.get()?"ON":"OFF");
//		printp("RL3: %s\n", relay3.get()?"ON":"OFF");
//		printp("RL4: %s\n", relay4.get()?"ON":"OFF");
//	}
//}
//extern const dbg_entry outputEntry = {debugOut, "o"};


//cAnalog analogIn1(4);


/* main program starts here */
int main(void)
{
	//WDTCSR = _BV(WDCE) | _BV(WDE);
	//WDTCSR = (_BV(WDP2) | _BV(WDP1) | _BV(WDP0) | _BV(WDE));

	sei();

	cOutput statusRed(0x60);
	cOutput statusGreen(0x61);
	cLED status(&statusRed, &statusGreen);
//
//	cOutput led1red(0x20);
//	cOutput led1green(0x21);
//	cLED led1(&led1red, &led1green);
//
//	cOutput led2red(0x22);
//	cOutput led2green(0x23);
//	cLED led2(&led2red, &led2green);
//
//	cOutput led3red(0x24);
//	cOutput led3green(0x25);
//	cLED led3(&led3red, &led3green);
//
//	cOutput led4red(0x26);
//	cOutput led4green(0x27);
//	cLED led4(&led4red, &led4green);

	cHeartbeat heartbeat(&status);

	while(1)
	{
		watchdogReset();

		Terminal.run();
		heartbeat.run();

		_delay_ms(100);
	}

	return 0;
}

