#include "modulelight.h"

void ModuleLight::Init(int chan) {
	SetChannel(chan);
}

void ModuleLight::Update(Stream* stream) {
	uint16_t vis, ir, lux;
	GetState(vis, ir, lux);

	m_visible.addValue(vis);
	m_IR.addValue(ir);
	m_lux.addValue(lux);

	if (m_timeout.hasTimedOut()) {
		vis = m_visible.value();
		ir = m_IR.value();
		lux = m_lux.value();

		if (vis != m_prevVisible || ir != m_prevIR || lux != m_prevLux) {
			printUpdateHeader(stream);
			stream->print(vis);
			stream->print(", ");
			stream->print(ir);
			stream->print(", ");
			stream->print(lux);
			stream->print("\r\n");

			m_prevVisible = vis;
			m_prevIR = ir;
			m_prevLux = lux;
			m_timeout = TimeOut(100);
		}
		m_visible.reset();
		m_IR.reset();
		m_lux.reset();
	}
}