#ifndef ARDUINO_FLOTILLA_MODULE_H
#define ARDUINO_FLOTILLA_MODULE_H

#include "Arduino.h"

class Module {
  private:
	int m_channel;
	bool m_connected;

  protected:
	Module();
	void SetChannel(int c);
	void printUpdateHeader(Stream* stream);

  public:
	int Channel();
	bool IsConnected();
	void SetConnected(bool c);
	virtual const char* Name() = 0;
	void OnEnquire(Stream* stream);
	virtual void Set(int* params, int paramc);
	virtual void Update(Stream* stream);
};

#endif
