#include "moduleweather.h"

void ModuleWeather::Init(int chan) {
	SetChannel(chan);
	m_prevPressure = 0;
	m_prevTemp = 0;
}

void ModuleWeather::Update(SerialStream* stream) {
	uint16_t temp, pressure;
	GetState(temp, pressure);

	if (temp != m_prevTemp || pressure != m_prevPressure) {
		printUpdateHeader(stream);
		printList(stream, temp, pressure);

		m_prevTemp = temp;
		m_prevPressure = pressure;
	}
}