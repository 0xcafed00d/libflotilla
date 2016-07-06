#ifndef ARDUINO_FLOTILLA_MODULEMOTOR_H
#define ARDUINO_FLOTILLA_MODULEMOTOR_H

#include "module.h"

class ModuleMotor : public Module {
  protected:
	virtual void SetMotor(int16_t val) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "motor";
	}

	virtual void Set(int* params, int paramc);
};

#endif
