#ifndef ARDUINO_FLOTILLA_MODULEMATRIX_H
#define ARDUINO_FLOTILLA_MODULEMATRIX_H

#include "module.h"

class ModuleMatrix : public Module {
  protected:
	virtual void SetMatrix(uint8_t* data, uint8_t brightness) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "matrix";
	}

	virtual void Set(int* params, int paramc);
};

#endif
