#ifndef ARDUINO_FLOTILLA_EEPROM_H
#define ARDUINO_FLOTILLA_EEPROM_H

#include "externalinterfaces.h"

template <typename type>
uint8_t checksum(type* data) {
	uint8_t chk = 0;
	for (size_t n = 0; n < sizeof(type); n++) {
		chk += ((uint8_t*)data)[n];
	}
	return ~chk + 1;
}

template <typename type>
int writeStructEEPROM(const type& s, int addr, PersistantStore* store) {
	store->writeBlock((void*)&s, addr, sizeof(type));
	return sizeof(type);
}

template <typename type>
int readStructEEPROM(type& s, int addr, PersistantStore* store) {
	store->readBlock((void*)&s, addr, sizeof(type));
	return sizeof(type);
}

#endif
