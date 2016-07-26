#ifndef ARDUINO_LIB_EXTERNAL_INTERFACES_H
#define ARDUINO_LIB_EXTERNAL_INTERFACES_H

#include <stddef.h>
#include <stdint.h>

struct SerialStream {
	virtual bool available() = 0;
	virtual int readChar() = 0;
	virtual void writeChar(int c) = 0;
	virtual void print(int v) = 0;
	virtual void print(const char* s) = 0;
};

struct PersistantStore {
	virtual void writeBlock(int offset, void* data, size_t len) = 0;
	virtual void readBlock(int offset, void* data, size_t len) = 0;
};

struct TimeOut {
	uint32_t end;
};

struct TimerUtil {
	virtual TimeOut make(uint32_t timeout) = 0;
	virtual bool hasTimedOut(TimeOut& t) = 0;
};

#endif