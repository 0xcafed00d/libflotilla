#ifndef ARDUINO_FLOTILLA_MODULERAINBOW_H
#define ARDUINO_FLOTILLA_MODULERAINBOW_H

#include "module.h"

class ModuleRainbow : public Module {
  protected:
	virtual void SetLED(int index, uint8_t r, uint8_t g, uint8_t b) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "rainbow";
	}

	virtual void Set(int* params, int paramc);
};

#endif
