#ifndef ARDUINO_FLOTILLA_MODULECOLOUR_H
#define ARDUINO_FLOTILLA_MODULECOLOUR_H

#include <Arduino.h>
#include "module.h"

class ModuleColour : public Module {
  private:
	int16_t m_prevR;
	int16_t m_prevG;
	int16_t m_prevB;
	int16_t m_prevC;

  protected:
	virtual void GetState(int16_t& r, int16_t& g, int16_t& b, int16_t& c) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "colour";
	}

	virtual void Update(Stream* stream);
};

#endif