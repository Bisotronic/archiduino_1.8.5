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
	file: ArchiduinoLcd_PCF.h			version: 1.0.0   10/06/2014
----------------------------------------------------------------------------
*/

#ifndef LCD1284_h
#define LCD1284_h

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <KEYPAD1284.h>

class LCD1284 : public LiquidCrystal_I2C, public KEYPAD1284
{
public: 
	LCD1284() : LiquidCrystal_I2C(0x20,16,2) {}
	LCD1284(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows) : LiquidCrystal_I2C::LiquidCrystal_I2C(lcd_Addr, lcd_cols, lcd_rows) {}

	void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);

};

#endif // ArchiduinoLcd_PCF_h

