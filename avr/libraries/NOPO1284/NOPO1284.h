#ifndef NOPO1284_H
#define NOPO1284_H

#include "Arduino.h"

	  
class NOPO1284
{
   private:
   
      byte I2CAddress;  	
	  byte TPIC2810_ADDRESS;
	  byte TPIC2810_SUBADDR = B01000100;
	  byte TPIC_DATA        = B00000000;
	  byte TPIC_CHANNEL		= B00000000;
	  uint8_t BYTE_VALUE    = B00000000;
	    
   public:

      void init 		(uint16_t addr);
      void on   		(byte TPIC_CHANNEL);
      void off  		(byte TPIC_CHANNEL);
	  void allOn        (void);
	  void allOff       (void);
	  void selOn		(uint8_t BYTE_VALUE);
	  void revert		(void);
	  byte status  		(void);
	  byte isOn			(byte TPIC_CHANNEL);
	  byte digitalRead  (byte TPIC_CHANNEL);
	  void execute		(byte TPIC_DATA);

};

#endif