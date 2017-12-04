#include "NOPO1284.h"  // Class declaration
#include <Wire.h>

//-------------------------------------------------------- INIT
void NOPO1284::init (uint16_t addr)
{
    TPIC2810_ADDRESS = addr;
	Wire.begin();
	off(B11111111);
}

//-------------------------------------------------------- ON
void NOPO1284::on(byte TPIC_CHANNEL)
{
	bitWrite(TPIC_DATA, TPIC_CHANNEL, 1);
	execute(TPIC_DATA);
}

//-------------------------------------------------------- ALL ON
void NOPO1284::allOn()
{
	execute(B11111111);
}

//-------------------------------------------------------- ALL OFF
void NOPO1284::allOff()
{
	execute(B00000000);
}

//-------------------------------------------------------- SELECTIVE ON
void NOPO1284::selOn(uint8_t BYTE_VALUE)
{
	execute(BYTE_VALUE);
}

//-------------------------------------------------------- REVERT STATE
void NOPO1284::revert()
{
	TPIC_DATA = ~(TPIC_DATA);
	execute(TPIC_DATA);
}

//-------------------------------------------------------- OFF
void NOPO1284::off(byte TPIC_CHANNEL)
{
	bitWrite(TPIC_DATA, TPIC_CHANNEL, 0);
	execute(TPIC_DATA);
}

//-------------------------------------------------------- IS ON?
byte NOPO1284::isOn(byte TPIC_CHANNEL)
{
	return bitRead(TPIC_DATA, TPIC_CHANNEL);
}

//-------------------------------------------------------- DIGITAL REAL
byte NOPO1284::digitalRead(byte TPIC_CHANNEL)
{
	return bitRead(TPIC_DATA, TPIC_CHANNEL);
}

//-------------------------------------------------------- STATUS
byte NOPO1284::status()
{
	return TPIC_DATA;
}

//-------------------------------------------------------- EXECUTE (PRIVATE)
void NOPO1284::execute(byte TPIC_DATA)
{
  Wire.beginTransmission(TPIC2810_ADDRESS);
	Wire.write(TPIC2810_SUBADDR);
	Wire.write(TPIC_DATA);    
  Wire.endTransmission();

}

