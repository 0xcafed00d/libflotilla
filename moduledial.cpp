#include "moduledial.h"

void ModuleDial::Init(int chan) {
	SetChannel(chan);
	m_prevState = 0xffff;  // initially set to impossible state so we get at least 1 update at start
}

void ModuleDial::Update(SerialStream* stream) {
	uint16_t newState = GetState();

	if (newState != m_prevState) {
		printUpdateHeader(stream);
		printList(stream, newState);
		m_prevState = newState;
	}
}
