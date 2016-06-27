#ifndef ARDUINO_FLOTILLA_MODULEMOTION_H
#define ARDUINO_FLOTILLA_MODULEMOTION_H

#include <Arduino.h>
#include "module.h"

struct Vector {
	int16_t x, y, z;

	bool operator==(Vector& that) {
		return x == that.x && y == that.y && z == that.z;
	}

	bool operator!=(Vector& that) {
		return !(*this == that);
	}
};

class ModuleMotion : public Module {
  private:
	Vector m_prevAccel;
	Vector m_prevMag;

  protected:
	virtual void GetState(Vector& accel, Vector& mag) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "motion";
	}

	virtual void Update(Stream* stream);
};

#endif