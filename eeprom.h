#ifndef ARDUINO_FLOTILLA_EEPROM_H
#define ARDUINO_FLOTILLA_EEPROM_H

#include <Arduino.h>

template <typename type>
int writeStructEEPROM(const type& s, int addr) {
	for (int n = 0; n < sizeof(type); n++) {
		int8_t val = ((int8_t*)&s)[n];
		EEPROM.write(addr + n, val);
		if (val != EEPROM.read(addr + n)) {
			return -1;
		}
	}
	return sizeof(type);
}

template <typename type>
int readStructEEPROM(type& s, int addr) {
	for (int n = 0; n < sizeof(type); n++) {
		((int8_t*)&s)[n] = EEPROM.read(addr + n);
	}
	return sizeof(type);
}

#endif
