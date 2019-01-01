#ifndef _FM24W256_H_
#define _FM24W256_H_

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Wire.h>

class TVA_FRAM {
	public:
	TVA_FRAM(void);
	uint16_t eraseDevice(void);
	void writeString(word Start_Add, String thestring, int sizeofarray);
	void WriteString(word Start_Add, byte theString[], int sizeofarray);
	void WriteByte(int i2c_addr, word address, byte data);
	byte ReadByte(uint16_t i2c_addr, uint16_t address);
	
};

#endif
