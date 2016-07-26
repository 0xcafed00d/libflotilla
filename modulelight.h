#ifndef ARDUINO_FLOTILLA_MODULELIGHT_H
#define ARDUINO_FLOTILLA_MODULELIGHT_H

#include "module.h"

class ModuleLight : public Module {
  private:
	uint16_t m_prevVisible;
	uint16_t m_prevIR;
	uint16_t m_prevLux;

  protected:
	virtual void GetState(uint16_t& visible, uint16_t& ir, uint16_t& lux) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "light";
	}

	virtual void Update(SerialStream* stream);
};

#endif