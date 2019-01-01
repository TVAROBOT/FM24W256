#include <stdlib.h>
#include <Wire.h>
#include "FM24W256.h"

TVA_FRAM::TVA_FRAM(void)
{
	wire.begin();
}

uint16_t TVA_FRAM::eraseDevice(void)
{
  uint16_t startmillis;
  uint16_t endmillis;
  startmillis = millis();
  uint16_t i = 0;
  Serial.println("Start erasing device");
  while ((i < Max_Mem_Addr)) {
    memw(Device_addr, i, 0x00);
    i++;
  }
  endmillis = millis();
  return endmillis - startmillis;
}

void TVA_FRAM::WriteString(word Start_Add, String thestring&, int sizeofarray)
{
  byte theString[sizeofarray];
  thestring.getBytes(theString, sizeofarray);
  for (int i = 0; i < sizeofarray - 1 ; i++)
  {
    memw(Device_addr, Start_Add + i, theString[i]);
    Serial.println(i);
  }
  Serial.println();
}

void TVA_FRAM::WriteString(word Start_Add, byte theString[], int sizeofarray)
{
  for (int i = 0; i < sizeofarray - 1; i++)
  {
    memw(Device_addr, Start_Add + i, theString[i]);
  }
}

void TVA_FRAM::WriteByte(int i2c_addr, word address, byte data)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((byte)lowByte(address));
  Wire.write((byte)highByte(address));
  Wire.write(data);
  Wire.endTransmission();
}

byte TVA_FRAM::ReadByte(uint16_t i2c_addr, uint16_t address)
{
  Wire.beginTransmission(i2c_addr);
  Wire.write((byte)lowByte(address));
  Wire.write((byte)highByte(address));
  Wire.endTransmission();
  Wire.requestFrom(i2c_addr, 1); //only one byte
  if (Wire.available())
  {
    return Wire.read();
  }
}
 