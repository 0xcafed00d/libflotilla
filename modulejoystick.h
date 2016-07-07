#ifndef ARDUINO_FLOTILLA_MODULEJOYSTICK_H
#define ARDUINO_FLOTILLA_MODULEJOYSTICK_H

#include <Arduino.h>
#include "module.h"

class ModuleJoystick : public Module {
  private:
	int16_t m_prevX;
	int16_t m_prevY;
	bool m_prevButton;

  protected:
	virtual void GetState(int16_t& x, int16_t& y, bool& button) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "joystick";
	}

	virtual void Update(Stream* stream);
};

#endif