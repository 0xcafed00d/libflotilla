#ifndef ARDUINO_FLOTILLA_MODULELIGHT_H
#define ARDUINO_FLOTILLA_MODULELIGHT_H

#include <Arduino.h>
#include "module.h"

class ModuleLight : public Module {
  private:
	uint16_t m_prevVisible;
	uint16_t m_prevIR;

  protected:
	virtual void GetState(uint16_t& visible, uint16_t& ir) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "light";
	}

	virtual void Update(Stream* stream);
};

#endif