#ifndef ARDUINO_FLOTILLA_MODULEDIAL_H
#define ARDUINO_FLOTILLA_MODULEDIAL_H

#include <Arduino.h>
#include "module.h"

class ModuleDial : public Module {
  private:
	uint16_t m_prevState;

  protected:
	virtual uint16_t GetState() = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "dial";
	}

	virtual void Update(Stream* stream);
};

#endif