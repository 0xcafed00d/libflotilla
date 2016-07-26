#ifndef ARDUINO_FLOTILLA_MODULE_H
#define ARDUINO_FLOTILLA_MODULE_H

#include "externalinterfaces.h"

class Module {
  private:
	int m_channel;
	bool m_connected;

  protected:
	Module();
	void SetChannel(int c);
	void printUpdateHeader(SerialStream* stream);

  public:
	int Channel();
	bool IsConnected();
	void SetConnected(bool c);
	virtual const char* Name() = 0;
	void OnEnquire(SerialStream* stream);
	virtual void Set(int* params, int paramc);
	virtual void Update(SerialStream* stream);
};

#endif
