#ifndef ARDUINO_FLOTILLA_MODULENUMBER_H
#define ARDUINO_FLOTILLA_MODULENUMBER_H

#include "module.h"

class ModuleNumber : public Module {
  protected:
	virtual void SetNumber(uint8_t* data, bool colon, bool apostrophe) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "number";
	}

	virtual void Set(int* params, int paramc);
};

#endif
