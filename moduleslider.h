#ifndef ARDUINO_FLOTILLA_MODULESLIDER_H
#define ARDUINO_FLOTILLA_MODULESLIDER_H

#include "module.h"

class ModuleSlider : public Module {
  private:
	uint16_t m_prevState;

  protected:
	virtual uint16_t GetState() = 0;

  public:
	void Init(int chan);

	const char* Name() {
		return "slider";
	}

	virtual void Update(SerialStream* stream);
};

#endif