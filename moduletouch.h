#ifndef ARDUINO_FLOTILLA_MODULETOUCH_H
#define ARDUINO_FLOTILLA_MODULETOUCH_H

#include "module.h"

class ModuleTouch : public Module {
  private:
	uint8_t m_prevState;

  protected:
	virtual uint8_t GetState() = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "touch";
	}

	virtual void Update(SerialStream* stream);
};

#endif