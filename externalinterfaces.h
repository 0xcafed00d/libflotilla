#ifndef ARDUINO_LIB_EXTERNAL_INTERFACES_H
#define ARDUINO_LIB_EXTERNAL_INTERFACES_H

#include <stddef.h>
#include <stdint.h>

struct SerialStream {
	virtual bool available() = 0;
	virtual int read() = 0;
	virtual void write(int c) = 0;
	virtual void print(int v) = 0;
	virtual void print(const char* s) = 0;
};

struct PersistantStore {
	virtual void writeBlock(void* data, int offset, size_t len) = 0;
	virtual void readBlock(void* data, int offset, size_t len) = 0;
};

struct TimeOut {
	uint32_t end;
};

struct TimerUtil {
	virtual TimeOut make(uint32_t timeout) = 0;
	virtual bool hasTimedOut(TimeOut& t) = 0;
};

#endif