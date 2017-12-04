#include "RELAY1284.h"  // Class declaration
#include <Wire.h>

//-------------------------------------------------------- INIT
void RELAY1284::init ()
{
    TPIC2810_ADDRESS = 0x64;
	Wire.begin();
	off(B11111111);
}

//-------------------------------------------------------- ON
void RELAY1284::on(byte TPIC_CHANNEL)
{
	bitWrite(TPIC_DATA, TPIC_CHANNEL, 0);
	execute(TPIC_DATA);
}

//-------------------------------------------------------- OFF
void RELAY1284::off(byte TPIC_CHANNEL)
{
	bitWrite(TPIC_DATA, TPIC_CHANNEL, 1);
	execute(TPIC_DATA);
}

//-------------------------------------------------------- STATUS
byte RELAY1284::status(byte TPIC_CHANNEL)
{
	return bitRead(TPIC_DATA, TPIC_CHANNEL);
}

//-------------------------------------------------------- EXECUTE (PRIVATE)
void RELAY1284::execute(byte TPIC_DATA)
{
  Wire.beginTransmission(TPIC2810_ADDRESS);
	Wire.write(TPIC2810_SUBADDR);
	Wire.write(TPIC_DATA);    
  Wire.endTransmission();

}

