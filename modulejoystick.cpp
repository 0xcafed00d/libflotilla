#include "modulejoystick.h"

void ModuleJoystick::Init(int chan) {
	SetChannel(chan);
	m_prevX = 0;
	m_prevY = 0;
	m_prevButton = false;
}

void ModuleJoystick::Update(SerialStream* stream) {
	int16_t x;
	int16_t y;
	bool button;

	GetState(x, y, button);

	if (x != m_prevX || y != m_prevY || button != m_prevButton) {
		printUpdateHeader(stream);
		printList(stream, button ? 1 : 0, x, y);
		m_prevX = x;
		m_prevY = y;
		m_prevButton = button;
	}
}
