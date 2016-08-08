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
	void printList(SerialStream* stream, int a);
	void printList(SerialStream* stream, int a, int b);
	void printList(SerialStream* stream, int a, int b, int c);
	void printList(SerialStream* stream, int a, int b, int c, int d);
	virtual void OnInit() {
	}

  public:
	int Channel();
	bool IsConnected();
	void SetConnected(bool c);
	virtual void Init(int channel) = 0;
	virtual const char* Name() = 0;
	void OnEnquire(SerialStream* stream);
	virtual void Set(int* params, int paramc);
	virtual void Update(SerialStream* stream);
};

#endif
