/*

  ARCHIDUINO by Seletronica s.a.s. - Via Degli Alpini 7 - 12020 VALGRANA (CN) - ITALY
  -----------------------------------------------------------------------------------
  Website and e-shop:         http://www.seletronica.com
  Documentation repository:   http://www.archiduino.com 
  -----------------------------------------------------------------------------------
  Written by: BisoTronic   -> http://www.bisotronic.it
  -----------------------------------------------------------------------------------
  This software is published "as is", without technical support, and with no 
  warranty, express or implied, as to its usefulness for any purpose. Anyway, if you 
  have any question or suggestion, please feel free to contact: info@bisotronic.it
  -----------------------------------------------------------------------------------
  
  This library is intended to be used with Analog Devices AD5663 dual 16 bit DAC.
  
*/  

#ifndef DAC5660_H
#define DAC5660_H

#include "Arduino.h"

static const byte DAC_A  	= B00000000;
static const byte DAC_B  	= B00000000;
static const byte DAC_ALL  	= B00000000;
static const byte RESET_ALL = B00000000;
	  
class DAC5660
{
   private:
		/*
		byte SCLK; 
		byte SYNC; 
		byte DATA;
		*/
   public:

		void init 		(byte MID);
		void write   	(byte DAC_CMD, uint16_t DACDataOut);
		void reset      (byte DAC_CMD);

};

#endif