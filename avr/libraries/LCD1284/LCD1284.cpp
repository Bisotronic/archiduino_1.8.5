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
	file: ArchiduinoLcd_PCF.cpp				version: 1.0.0   10/06/2014
----------------------------------------------------------------------------
*/

#include <LCD1284.h>

void LCD1284::begin(uint8_t cols, uint8_t rows, uint8_t charsize){

	LiquidCrystal_I2C::begin(cols, rows, charsize);

	InitKeypad();
}
