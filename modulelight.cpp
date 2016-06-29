#include "modulelight.h"

void ModuleLight::Init(int chan) {
	SetChannel(chan);
	m_prevVisible = 0;
	m_prevIR = 0;
	m_prevLux = 0;
}

void ModuleLight::Update(Stream* stream) {
	uint16_t vis, ir, lux;
	GetState(vis, ir, lux);

	if (m_timeout.hasTimedOut() && (vis != m_prevVisible || vis != m_prevIR || vis != m_prevLux)) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(" ");
		stream->print(vis);
		stream->print(", ");
		stream->print(ir);
		stream->print(", ");
		stream->print(lux);
		stream->print("\r\n");

		m_prevVisible = vis;
		m_prevIR = ir;
		m_timeout = TimeOut(100);
	}
}