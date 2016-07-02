#ifndef ARDUINO_FLOTILLA_EEPROM_H
#define ARDUINO_FLOTILLA_EEPROM_H

#include <Arduino.h>
#include <avr/eeprom.h>

template <typename type>
uint8_t checksum(type* data) {
	uint8_t chk = 0;
	for (int n = 0; n < sizeof(type); n++) {
		chk += ((uint8_t*)data)[n];
	}
	return ~chk + 1;
}

template <typename type>
int writeStructEEPROM(const type& s, int addr) {
	for (int n = 0; n < sizeof(type); n++) {
		int8_t val = ((int8_t*)&s)[n];
		eeprom_write_byte(addr + n, val);
		if (val != eeprom_read_byte(addr + n)) {
			return -1;
		}
	}
	return sizeof(type);
}

template <typename type>
int readStructEEPROM(type& s, int addr) {
	for (int n = 0; n < sizeof(type); n++) {
		((int8_t*)&s)[n] = eeprom_read_byte(addr + n);
	}
	return sizeof(type);
}

#endif
