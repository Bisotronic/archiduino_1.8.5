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
	file: ArchiduinoLcdKeypad.h			version: 1.0.0   10/06/2014
----------------------------------------------------------------------------
*/

#ifndef KEYPAD1284_h
#define KEYPAD1284_h

#include "Arduino.h"

static const byte _SELECT = 0x01;
static const byte _ENTER = 0x02;
static const byte _DOWN = 0x04;
static const byte _UP  = 0x08;

class KEYPAD1284
{
	
private:

	int  _keyOff;
	int  _keyValue;
	byte PRESSED_BUTTON = 0;
	
public: 

	KEYPAD1284();
	
	void ledOn();
	void ledOff();
	bool button (byte PRESSED_BUTTON);
	
protected:

	uint8_t readButton();
	void InitKeypad();



};

#endif // ArchiduinoLcdKeypad_h

