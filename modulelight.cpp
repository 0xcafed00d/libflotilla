#include "modulelight.h"

void ModuleLight::Init(int chan) {
	SetChannel(chan);
	m_prevVisible = 0;
	m_prevIR = 0;
	m_prevLux = 0;
}

void ModuleLight::Update(SerialStream* stream) {
	uint16_t vis, ir, lux;
	GetState(vis, ir, lux);

	if (vis != m_prevVisible || ir != m_prevIR || lux != m_prevLux) {
		printUpdateHeader(stream);
		printList(stream, vis, ir, lux);

		m_prevVisible = vis;
		m_prevIR = ir;
		m_prevLux = lux;
	}
}