#ifndef ARDUINO_FLOTILLA_MODULE_H
#define ARDUINO_FLOTILLA_MODULE_H

#include "Arduino.h"

class Module {
  private:
	int m_channel;
	bool m_connected;

  protected:
	Module() : m_connected(true) {
	}

	void SetChannel(int c) {
		m_channel = c;
	}

	void printUpdateHeader(Stream* stream) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(" ");
	}

  public:
	int Channel() {
		return m_channel;
	}

	bool IsConnected() {
		return m_connected;
	}

	void SetConnected(bool c) {
		m_connected = c;
	}

	virtual const char* Name() = 0;

	void OnEnquire(Stream* stream) {
		stream->print("c ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print("\r\n");
	}

	virtual void Set(int* params, int paramc) {
	}

	virtual void Update(Stream* stream) {
	}
};

#endif
