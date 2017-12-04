/*
----------------------------------------------------------------------------
		  				ARCHIDUINO IS
				Board ARDUINO SOFTWARE compatible.
----------------------------------------------------------------------------

						ARCHIDUINO Library
					Created by Seletronica
						Copyright 2014
	Under creative commons license 3.0 - Attribution-ShareAlike
					 http://www.archiduino.com/

  This software is furnished "as is", without technical support, and with
  no warranty, express or implied, as to its usefulness for any purpose.

----------------------------------------------------------------------------
	file: pins_arduino.h			version: 1.0.0   10/06/2014
----------------------------------------------------------------------------
*/
/*

  original file:
  pins_arduino.h - Pin definition functions for Arduino Leonardo
  Part of Arduino - http://www.arduino.cc/

  Modified from the original version of Arduino Leonardo
  and adapted for Archiduino to implement the needed ports

*/


#include <Arduino.h>

#ifndef Guarduino_h
#define Guarduino_h

#ifdef __cplusplus
extern "C"{
#endif

// wiring_digital_ex.cpp
void pinModeEx(uint8_t, uint8_t);
void digitalWriteEx(uint8_t, uint8_t);
int digitalReadEx(uint8_t);

#define digitalPinToPortEx(P) ( pgm_read_byte( uP32u4_port_mask + (P) ) )
#define digitalPinToBitMaskEx(P) ( pgm_read_byte( uP32u4_bit_mask + (P) ) )
#define digitalPinToTimerEx(P) ( pgm_read_byte( uP32u4_timer_mask + (P) ) )

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif


#ifdef __cplusplus
} // extern "C"
#endif


#ifndef ARDUINO_MAIN
#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12
#endif

#define NOT_CONNECT	32

#ifdef __AVR_ATmega32U4__
// Mapping pin port
#undef  PB0 
#undef  PB1 
#undef  PB2 
#undef  PB3 
#undef  PB4 
#undef  PB5 
#undef  PB6 
#undef  PB7 
#undef  PC6 
#undef  PC7 
#undef  PD0 
#undef  PD1 
#undef  PD2 
#undef  PD3 
#undef  PD4 
#undef  PD5 
#undef  PD6 
#undef  PD7 
#undef  PE2 
#undef  PE6 
#undef  PF0 
#undef  PF1 
#undef  PF4 
#undef  PF5 
#undef  PF6 
#undef  PF7 

#define  PB0 17
#define  PB1 15
#define  PB2 16
#define  PB3 14
#define  PB4 26
#define  PB5 27
#define  PB6 28
#define  PB7 11
#define  PC6 5
#define  PC7 13
#define  PD0 3
#define  PD1 2
#define  PD2 0
#define  PD3 1
#define  PD4 24
#define  PD5 30
#define  PD6 29
#define  PD7 25
#define  PE2 31
#define  PE6 7
#define  PF0 23
#define  PF1 22
#define  PF4 21
#define  PF5 20
#define  PF6 19
#define  PF7 18
// Mapping pin of slot modules

#undef LED_BUILTIN

//implemented output
static const uint8_t LED_RUN = PF6;
static const uint8_t LED_BUILTIN = PF6;
static const uint8_t LCD_BKLIGHT = PD5;
static const uint8_t LCD_BUTTON = PF4;

// special pins GuardUino

static const uint8_t LED1 		= PF6;
static const uint8_t LED2 		= PF7;
static const uint8_t OPTO1 		= PC7;
static const uint8_t OPTO2 		= PD7;
static const uint8_t RELAY 		= PC6;
static const uint8_t RXD1 		= PD2;
static const uint8_t TXD1 		= PD3;
static const uint8_t ONEW1 		= PE6;
static const uint8_t ONEW2 		= PD6;
static const uint8_t LED1W 		= PD5;
static const uint8_t LED2W 		= PE2;
static const uint8_t BUZZ		= PF5;
static const uint8_t BUTTON1 	= PF0;
static const uint8_t BUTTON2 	= PF1;
static const uint8_t CARD 		= PD4;

#endif

#ifndef Pins_Arduino_h
// Mapping of analog pins as digital I/O
// A6-A11 share with digital pins
static const uint8_t A0 = 18;
static const uint8_t A1 = 19;
static const uint8_t A2 = 20;
static const uint8_t A3 = 21;
static const uint8_t A4 = 22;
static const uint8_t A5 = 23;
static const uint8_t A6 = 24;
static const uint8_t A7 = 25;
static const uint8_t A8 = 26;
static const uint8_t A9 = 27;
static const uint8_t A10 = 28;
static const uint8_t A11 = 29;
#endif

const uint8_t PROGMEM uP32u4_port_mask[] = {

	PD, // D0 - PD2
	PD,	// D1 - PD3
	PD, // D2 - PD1
	PD,	// D3 - PD0
	PD,	// D4 - PD4
	PC, // D5 - PC6
	PD, // D6 - PD7
	PE, // D7 - PE6
	
	PB, // D8 - PB4
	PB,	// D9 - PB5
	PB, // D10 - PB6
	PB,	// D11 - PB7
	PD, // D12 - PD6
	PC, // D13 - PC7
	
	PB,	// D14 - MISO - PB3
	PB,	// D15 - SCK - PB1
	PB,	// D16 - MOSI - PB2
	PB,	// D17 - SS - PB0
	
	PF,	// D18 - A0 - PF7
	PF, // D19 - A1 - PF6
	PF, // D20 - A2 - PF5
	PF, // D21 - A3 - PF4
	PF, // D22 - A4 - PF1
	PF, // D23 - A5 - PF0
	
	PD, // D24 - A6 - PD4
	PD, // D25 - A7 - PD7
	PB, // D26 - A8 - PB4
	PB, // D27 - A9 - PB5
	PB, // D28 - A10 - PB6
	PD, // D29 - A11 - PD6

	//implemented port
	PD, // D30 - PD5
	PE, // D31 - PE2

	NOT_CONNECT,  //32

};

const uint8_t PROGMEM uP32u4_bit_mask[] = {

	_BV(2), // D0 - PD2
	_BV(3),	// D1 - PD3
	_BV(1), // D2 - PD1
	_BV(0),	// D3 - PD0
	_BV(4),	// D4 - PD4
	_BV(6), // D5 - PC6
	_BV(7), // D6 - PD7
	_BV(6), // D7 - PE6
	
	_BV(4), // D8 - PB4
	_BV(5),	// D9 - PB5
	_BV(6), // D10 - PB6
	_BV(7),	// D11 - PB7
	_BV(6), // D12 - PD6
	_BV(7), // D13 - PC7
	
	_BV(3),	// D14 - MISO - PB3
	_BV(1),	// D15 - SCK - PB1
	_BV(2),	// D16 - MOSI - PB2
	_BV(0),	// D17 - SS - PB0
	
	_BV(7),	// D18 - A0 - PF7
	_BV(6), // D19 - A1 - PF6
	_BV(5), // D20 - A2 - PF5
	_BV(4), // D21 - A3 - PF4
	_BV(1), // D22 - A4 - PF1
	_BV(0), // D23 - A5 - PF0
	
	_BV(4), // D24 - A6 - PD4
	_BV(7), // D25 - A7 - PD7
	_BV(4), // D26 - A8 - PB4
	_BV(5), // D27 - A9 - PB5
	_BV(6), // D28 - A10 - PB6
	_BV(6), // D29 - A11 - PD6

	//implemented bit
	_BV(5), // D30 - PD5
	_BV(2), // D31 - PE2

	NOT_CONNECT,  //32
};

const uint8_t PROGMEM uP32u4_timer_mask[] = {

	NOT_ON_TIMER,	
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER0B,		/* 3 */
	NOT_ON_TIMER,
	TIMER3A,		/* 5 */
	TIMER4D,		/* 6 */
	NOT_ON_TIMER,	
	
	NOT_ON_TIMER,	
	TIMER1A,		/* 9 */
	TIMER1B,		/* 10 */
	TIMER0A,		/* 11 */
	
	NOT_ON_TIMER,	
	TIMER4A,		/* 13 */
	
	NOT_ON_TIMER,	
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,

	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	NOT_ON_TIMER,

	//implemented timer
	NOT_ON_TIMER,
	NOT_ON_TIMER,
};

#ifdef __cplusplus
extern "C"{
#endif

static void turnOffPwmEx(uint8_t timer)	// TODO: Da sistemare
{
	switch (timer)
	{
		#if defined(TCCR1A) && defined(COM1A1)
		case TIMER1A:   cbi(TCCR1A, COM1A1);    break;
		#endif
		#if defined(TCCR1A) && defined(COM1B1)
		case TIMER1B:   cbi(TCCR1A, COM1B1);    break;
		#endif
		
		#if defined(TCCR2) && defined(COM21)
		case  TIMER2:   cbi(TCCR2, COM21);      break;
		#endif
		
		#if defined(TCCR0A) && defined(COM0A1)
		case  TIMER0A:  cbi(TCCR0A, COM0A1);    break;
		#endif
		
		#if defined(TIMER0B) && defined(COM0B1)
		case  TIMER0B:  cbi(TCCR0A, COM0B1);    break;
		#endif
		#if defined(TCCR2A) && defined(COM2A1)
		case  TIMER2A:  cbi(TCCR2A, COM2A1);    break;
		#endif
		#if defined(TCCR2A) && defined(COM2B1)
		case  TIMER2B:  cbi(TCCR2A, COM2B1);    break;
		#endif
		
		#if defined(TCCR3A) && defined(COM3A1)
		case  TIMER3A:  cbi(TCCR3A, COM3A1);    break;
		#endif
		#if defined(TCCR3A) && defined(COM3B1)
		case  TIMER3B:  cbi(TCCR3A, COM3B1);    break;
		#endif
		#if defined(TCCR3A) && defined(COM3C1)
		case  TIMER3C:  cbi(TCCR3A, COM3C1);    break;
		#endif

		#if defined(TCCR4A) && defined(COM4A1)
		case  TIMER4A:  cbi(TCCR4A, COM4A1);    break;
		#endif					
		#if defined(TCCR4A) && defined(COM4B1)
		case  TIMER4B:  cbi(TCCR4A, COM4B1);    break;
		#endif
		#if defined(TCCR4A) && defined(COM4C1)
		case  TIMER4C:  cbi(TCCR4A, COM4C1);    break;
		#endif			
		#if defined(TCCR4C) && defined(COM4D1)
		case TIMER4D:	cbi(TCCR4C, COM4D1);	break;
		#endif			
			
		#if defined(TCCR5A)
		case  TIMER5A:  cbi(TCCR5A, COM5A1);    break;
		case  TIMER5B:  cbi(TCCR5A, COM5B1);    break;
		case  TIMER5C:  cbi(TCCR5A, COM5C1);    break;
		#endif
	}
}

void pinModeEx(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMaskEx(pin);
	uint8_t port = digitalPinToPortEx(pin);
	volatile uint8_t *reg, *out;

	if (port == NOT_A_PIN) return;
	if (port == NOT_CONNECT) return;

	// JWS: can I let the optimizer do this?
	reg = portModeRegister(port);
	out = portOutputRegister(port);

	if (mode == INPUT) { 
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out &= ~bit;
		SREG = oldSREG;
	} else if (mode == INPUT_PULLUP) {
		uint8_t oldSREG = SREG;
                cli();
		*reg &= ~bit;
		*out |= bit;
		SREG = oldSREG;
	} else {
		uint8_t oldSREG = SREG;
                cli();
		*reg |= bit;
		SREG = oldSREG;
	}
}

void digitalWriteEx(uint8_t pin, uint8_t val)
{
	uint8_t timer = digitalPinToTimerEx(pin);
	uint8_t bit = digitalPinToBitMaskEx(pin);
	uint8_t port = digitalPinToPortEx(pin);
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;
	if (port == NOT_CONNECT) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER)
		turnOffPwmEx(timer);

	out = portOutputRegister(port);

	uint8_t oldSREG = SREG;
	cli();

	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}

	SREG = oldSREG;
}

int digitalReadEx(uint8_t pin)
{
	uint8_t timer = digitalPinToTimerEx(pin);
	uint8_t bit = digitalPinToBitMaskEx(pin);
	uint8_t port = digitalPinToPortEx(pin);

	if (port == NOT_A_PIN) return LOW;
	if (port == NOT_CONNECT) return LOW;

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	if (timer != NOT_ON_TIMER) turnOffPwmEx(timer);

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* Pins_Archiduino_h */
