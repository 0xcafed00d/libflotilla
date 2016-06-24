#include "modulelight.h"

void ModuleLight::Init(int chan) {
	SetChannel(chan);
	m_prevVisible = 0;
	m_prevIR = 0;  
}

void ModuleLight::Update(Stream* stream) {
	uint16_t vis, ir;
	GetState(vis, ir);

	if (vis != m_prevVisible || vis != m_prevIR) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(" ");
		stream->print(vis);
		stream->print(", ");
		stream->print(ir);
		stream->print("\r\n");

		m_prevVisible = vis;
		m_prevIR = ir;
	}
}