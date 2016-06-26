#include "moduleweather.h"

void ModuleWeather::Init(int chan) {
	SetChannel(chan);
	m_prevPressure = 0;
	m_prevTemp = 0;  
}

void ModuleWeather::Update(Stream* stream) {
	uint16_t temp, pressure;
	GetState(temp, pressure);

	if (temp != m_prevTemp || pressure != m_prevPressure) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(" ");
		stream->print(temp);
		stream->print(", ");
		stream->print(pressure);
		stream->print("\r\n");

		m_prevTemp = temp;
		m_prevPressure = pressure;
	}
}