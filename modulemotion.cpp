#include "modulemotion.h"

void ModuleMotion::Init(int chan) {
	SetChannel(chan);
	m_prevAccel = Vector<int16_t>{};
	m_prevMag = Vector<int16_t>{};
}

void printVector(Stream* stream, const Vector<int16_t>& v) {
	stream->print(v.x);
	stream->print(", ");
	stream->print(v.y);
	stream->print(", ");
	stream->print(v.z);
}

void ModuleMotion::Update(Stream* stream) {
	Vector<int16_t> accel, mag;
	GetState(accel, mag);

	if (accel != m_prevAccel || mag != m_prevMag) {
		printUpdateHeader(stream);
		printVector(stream, accel);
		stream->print(", ");
		printVector(stream, mag);
		stream->print("\r\n");

		m_prevAccel = accel;
		m_prevMag = mag;
	}
}