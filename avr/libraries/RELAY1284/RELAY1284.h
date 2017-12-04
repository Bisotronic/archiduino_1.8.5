#ifndef RELAY1284_H
#define RELAY1284_H

#include "Arduino.h"

#ifdef ARCHIDUINO1284_BT
	static const byte REL_M7  = 0; // 1;   //B00000001;
	static const byte REL_M10 = 1; // 2;   //B00000010;
	static const byte REL_M12 = 2; // 4;   //B00000100;
	static const byte REL_M11 = 3; // 8;   //B00001000;
	static const byte REL_M6  = 4; // 16;  //B00010000;
	static const byte REL_M5  = 5; // 32;  //B00100000;
	static const byte REL_M8  = 6; // 64;  //B01000000;
	static const byte REL_M9  = 7; // 128; //B10000000;
#else
	static const byte REL_M4  = 0; // 1;   //B00000001;
	static const byte REL_M10 = 1; // 2;   //B00000010;
	static const byte REL_M12 = 2; // 4;   //B00000100;
	static const byte REL_M11 = 3; // 8;   //B00001000;
	static const byte REL_M6  = 4; // 16;  //B00010000;
	static const byte REL_M5  = 5; // 32;  //B00100000;
	static const byte LCD_BKL = 6; // 64;  //B01000000;
	static const byte REL_M9  = 7; // 128; //B10000000;
#endif
	  
class RELAY1284
{
   private:
   
      byte I2CAddress;  	
	  byte TPIC2810_ADDRESS;
	  byte TPIC2810_SUBADDR = B01000100;
	  byte TPIC_DATA        = B00000000;
	  byte TPIC_CHANNEL		= B00000000;
	    
   public:

      void init 		();
      void on   		(byte TPIC_CHANNEL);
      void off  		(byte TPIC_CHANNEL);
	  byte status  		(byte TPIC_CHANNEL);
	  void execute		(byte TPIC_DATA);

};

#endif