#include "modulecolour.h"

void ModuleColour::Init(int chan) {
	SetChannel(chan);
	m_prevR = 0;
	m_prevG = 0;
	m_prevB = 0;
	m_prevC = 0;
}

void ModuleColour::Update(Stream* stream) {
	int16_t r, g, b, c;
	GetState(r, g, b, c);

	if (r != m_prevR || g != m_prevG || b != m_prevG || c != m_prevC) {
		printUpdateHeader(stream);
		stream->print(r);
		stream->print(',');
		stream->print(g);
		stream->print(',');
		stream->print(b);
		stream->print(',');
		stream->print(c);
		stream->print("\r\n");

		m_prevR = r;
		m_prevG = g;
		m_prevB = b;
		m_prevC = c;
	}
}
