#include "moduledial.h"

void ModuleDial::Init(int chan) {
	SetChannel(chan);
	m_prevState = 0xffff;  // initially set to impossible state so we get at least 1 update at start
}

void ModuleDial::Update(Stream* stream) {
	uint16_t newState = GetState();

	if (newState != m_prevState) {
		printUpdateHeader(stream);
		stream->print(newState);
		stream->print("\r\n");
		m_prevState = newState;
	}
}
