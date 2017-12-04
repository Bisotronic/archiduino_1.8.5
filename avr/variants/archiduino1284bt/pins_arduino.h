#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>
//#include <Arduino.h>

#define ARCHIDUINO_1284BT

#define NUM_DIGITAL_PINS            32
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 14 : -1)
#define ifpin(p,what,ifnot)         (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (what) : (ifnot))
#define digitalPinHasPWM(p)         ifpin(p,pgm_read_byte(digital_pin_to_timer_PGM + (p)) != NOT_ON_TIMER,1==0)
#define digitalPinToAnalogPin(p)    ( (p) >= 14 && (p) <= 21 ? (p) - 14 : -1 )
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS) ? (7 - (p)) : ((p)  >=  14 && (p) <= 21) ? (21 - (p)) : -1    

static const uint8_t SS   = 10;
static const uint8_t MOSI = 11;
static const uint8_t MISO = 12;
static const uint8_t SCK  = 13;

static const uint8_t SDA = 23;
static const uint8_t SCL = 22;

static const uint8_t A0 = 14;
static const uint8_t A1 = 15;
static const uint8_t A2 = 16;
static const uint8_t A3 = 17;
static const uint8_t A4 = 18;
static const uint8_t A5 = 19;
static const uint8_t A6 = 20;
static const uint8_t A7 = 21;

#define PORT_NDX_TO_PCMSK(x) ((x) == 0 ? &PCMSK0 : ((x) == 1 ? &PCMSK1 : ((x) == 2 ? &PCMSK2 : ((x) == 3 ? &PCMSK3 : (uint8_t )0))))

#define digitalPinToPCICR(p)    ifpin(p,&PCICR,(uint8_t *)0)
#define digitalPinToPCICRbit(p) ifpin(p,digital_pin_to_pcint[p] >> 3,0)
#define digitalPinToPCMSK(p)    ifpin(p,(uint8_t *)PORT_NDX_TO_PCMSK(digital_pin_to_pcint[p] >> 3),(uint8_t *)0)
#define digitalPinToPCMSKbit(p) ifpin(p,digital_pin_to_pcint[p] & 0x7,0)

#define digitalPinToInterrupt(p)  ((p) == 6 ? 0 : ((p) == 7 ? 1 : ((p) == 2 ? 2 : NOT_AN_INTERRUPT))

#undef  PA0 
#undef  PA1 
#undef  PA2 
#undef  PA3 
#undef  PA4 
#undef  PA5 
#undef  PA6 
#undef  PA7 
#undef  PB0 
#undef  PB1 
#undef  PB2 
#undef  PB3 
#undef  PB4 
#undef  PB5 
#undef  PB6 
#undef  PB7 
#undef  PC0 
#undef  PC1 
#undef  PC2 
#undef  PC3 
#undef  PC4 
#undef  PC5 
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

#define  PA0 21  	//A7
#define  PA1 20  	//A6
#define  PA2 19  	//A5
#define  PA3 18  	//A4   
#define  PA4 17  	//A3			
#define  PA5 16  	//A2    
#define  PA6 15  	//A1 
#define  PA7 14  	//A0
#define  PB0 4	 	//D4
#define  PB1 5		//D5	
#define  PB2 2		//D2
#define  PB3 3		//D3
#define  PB4 10		//D10	SS
#define  PB5 11		//D11	MOSI
#define  PB6 12		//D12	MISO
#define  PB7 13		//D13	SCLK
#define  PC0 22     //D22	SCL
#define  PC1 23     //D23	SDA
#define  PC2 24		//D24
#define  PC3 25		//D25
#define  PC4 26		//D26
#define  PC5 27		//D27
#define  PC6 28		//D28
#define  PC7 29		//D29
#define  PD0 0		//D0
#define  PD1 1		//D1
#define  PD2 6		//D6	RXD1
#define  PD3 7		//D7	TXD1
#define  PD4 30		//D30
#define  PD5 8		//D8
#define  PD6 9		//D9
#define  PD7 31		//D31

static const uint8_t M1A = PB6;	// MISO	
static const uint8_t M1B = PB5;	// MOSI
static const uint8_t M1C = PB7;	// SCLK
static const uint8_t M1D = PB4;	// SS
static const uint8_t M2A = PD3;	// TXD1
static const uint8_t M2B = PD2;	// RXD1 
static const uint8_t M2C = PD5;	// CS_ENC / TX_EN RS485
static const uint8_t M3A = PD1;	// TXD0
static const uint8_t M3B = PD0;	// RXD0
static const uint8_t M4A = PD6;	// LED
static const uint8_t M4B = PD7;	// CS_SD
static const uint8_t M5A = PC5; 
static const uint8_t M5B = PC6;
static const uint8_t M6A = PC0;	// SCL
static const uint8_t M6B = PC1;	// SDA
static const uint8_t M7A = PA0;
static const uint8_t M7B = PA1;
static const uint8_t M8A = PA2;
static const uint8_t M8B = PA3;
static const uint8_t M9A = PA4;
static const uint8_t M9B = PA5;
static const uint8_t M10A = PA6;
static const uint8_t M10B = PA7;
static const uint8_t M11A = PD4;
static const uint8_t M11B = PC4;
static const uint8_t M12A = PB0;
static const uint8_t M12B = PB1;


static const uint8_t LED     		= PD6; // also available on D9 
static const uint8_t LED_RUN 		= PD6; // backward compatibility with Archiduino 32U4
static const uint8_t LCD_BUTTON 	= PA7; // backward compatibility with Archiduino 32U4


#define PA 1
#define PB 2
#define PC 3
#define PD 4

#ifndef ARDUINO_MAIN
extern const uint8_t digital_pin_to_pcint[];
#else
const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
  24, // D0  PD0
  25, // D1  PD1 1
  10, // D2  PB2
  11, // D3  PB3
  8,  // D4  PB0
  9,  // D5  PB1 5
  26, // D6  PD2
  27, // D7  PD3  
  29, // D8  PD5
  30, // D9  PD6 9
  12, // D10 PB4
  13, // D11 PB5
  14, // D12 PB6
  15, // D13 PB7 13
  7,  // D14 PA7
  6,  // D15 PA6
  5,  // D16 PA5
  4,  // D17 PA4
  3,  // D18 PA3
  2,  // D19 PA2
  1,  // D20 PA1
  0,  // D21 PA0 21
  16, // D22 PC0
  17, // D23 PC1
  18, // D24 PC2
  19, // D25 PC3
  20, // D26 PC4
  21, // D27 PC5
  22, // D28 PC6
  23, // D29 PC7 29
  28, // D30 PD4
  31  // D31 PD7 31
};


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
	NOT_A_PORT,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
  PD, // D0
  PD, // D1
  PB, // D2
  PB, // D3  
  PB, // D4
  PB, // D5
  PD, // D6
  PD, // D7
  PD, // D8
  PD, // D9
  PB, // D10
  PB, // D11
  PB, // D12
  PB, // D13
  PA, // D14
  PA, // D15
  PA, // D16
  PA, // D17
  PA, // D18
  PA, // D19
  PA, // D20
  PA, // D21
  PC, // D22
  PC, // D23
  PC, // D24
  PC, // D25
  PC, // D26
  PC, // D27
  PC, // D28
  PC, // D29
  PD, // D30
  PD, // D31
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
  _BV(0), // D0  PD0
  _BV(1), // D1  PD1
  _BV(2), // D2  PB2
  _BV(3), // D3  PB3
  _BV(0), // D4  PB0
  _BV(1), // D5  PB1
  _BV(2), // D6  PD2
  _BV(3), // D7  PD3  
  _BV(5), // D8  PD5
  _BV(6), // D9  PD6
  _BV(4), // D10 PB4
  _BV(5), // D11 PB5
  _BV(6), // D12 PB6
  _BV(7), // D13 PB7
  _BV(7), // D14 PA7 (A0)
  _BV(6), // D15 PA6 (A1)
  _BV(5), // D16 PA5 (A2)
  _BV(4), // D17 PA4 (A3)
  _BV(3), // D18 PA3 (A4)
  _BV(2), // D19 PA2 (A5)
  _BV(1), // D20 PA1 (A6)
  _BV(0), // D21 PA0 (A7)
  _BV(0), // D22 PC0
  _BV(1), // D23 PC1
  _BV(2), // D24 PC2
  _BV(3), // D25 PC3
  _BV(4), // D26 PC4
  _BV(5), // D27 PC5
  _BV(6), // D28 PC6
  _BV(7), // D29 PC7
  _BV(4), // D30 PD4
  _BV(7), // D31 PD7
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, // D0  PD0
  NOT_ON_TIMER, // D1  PD1
  NOT_ON_TIMER, // D2  PB2
  TIMER0A,      // D3  PB3
  NOT_ON_TIMER, // D4  PB0
  NOT_ON_TIMER, // D5  PB1
  NOT_ON_TIMER, // D6  PD2
  NOT_ON_TIMER, // D7  PD3  
  TIMER1A,      // D8  PD5
  TIMER2B,      // D9  PD6
  TIMER0B,      // D10 PB4
  NOT_ON_TIMER, // D11 PB5
  TIMER3A,      // D12 PB6
  TIMER3B,      // D13 PB7
  NOT_ON_TIMER, // D14 PA0
  NOT_ON_TIMER, // D15 PA1
  NOT_ON_TIMER, // D16 PA2
  NOT_ON_TIMER, // D17 PA3
  NOT_ON_TIMER, // D18 PA4
  NOT_ON_TIMER, // D19 PA5
  NOT_ON_TIMER, // D20 PA6
  NOT_ON_TIMER, // D21 PA7
  NOT_ON_TIMER, // D22 PC0
  NOT_ON_TIMER, // D23 PC1
  NOT_ON_TIMER, // D24 PC2
  NOT_ON_TIMER, // D25 PC3
  NOT_ON_TIMER, // D26 PC4
  NOT_ON_TIMER, // D27 PC5
  NOT_ON_TIMER, // D28 PC6
  NOT_ON_TIMER, // D29 PC7
  TIMER1B,      // D30 PD4
  TIMER2A,      // D31 PD7
};


#endif // ARDUINO_MAIN

#endif // Pins_Arduino_h
// vim:ai:cin:sts=2 sw=2 ft=cpp
