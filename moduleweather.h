#ifndef ARDUINO_FLOTILLA_MODULEWEATHER_H
#define ARDUINO_FLOTILLA_MODULEWEATHER_H

#include "module.h"

class ModuleWeather : public Module {
  private:
	uint16_t m_prevTemp;
	uint16_t m_prevPressure;

  protected:
	virtual void GetState(uint16_t& temp, uint16_t& pressure) = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "weather";
	}

	virtual void Update(SerialStream* stream);
};

#endif