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
	file: KEYPAD1284.cpp		version: 1.0.0   10/06/2014
----------------------------------------------------------------------------
*/

//#include <Archiduino.h>
#include <KEYPAD1284.h>


KEYPAD1284::KEYPAD1284(){
	//led run is output
	pinMode(LED_RUN, OUTPUT);
	_keyOff = 1;
}

void KEYPAD1284::ledOff() {
	//led run off
	digitalWrite(LED_RUN, LOW);  
}

void KEYPAD1284::ledOn() {
	//led run on
	digitalWrite(LED_RUN, HIGH);  
}

uint8_t KEYPAD1284::readButton() {

	_keyValue = analogRead(LCD_BUTTON);
	float _r = _keyValue/(_keyOff * 2.0);
	return (uint8_t)floor((15-30 * _r)/(1 - _r) + 0.5);
}

void KEYPAD1284::InitKeypad() {

	_keyOff = analogRead(LCD_BUTTON);
}

bool KEYPAD1284::button(byte PRESSED_BUTTON){
	return (readButton() & PRESSED_BUTTON);
}




