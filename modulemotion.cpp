#include "modulemotion.h"

void ModuleMotion::Init(int chan) {
	SetChannel(chan);
	m_prevAccel = Vector{};
	m_prevMag = Vector{};
}

void printVector(Stream* stream, const Vector& v) {
	stream->print(v.x);
	stream->print(", ");
	stream->print(v.y);
	stream->print(", ");
	stream->print(v.z);
}

void ModuleMotion::Update(Stream* stream) {
	Vector accel, mag;
	GetState(accel, mag);

	if (accel != m_prevAccel || mag != m_prevMag) {
		stream->print("u ");
		stream->print(Channel());
		stream->print("/");
		stream->print(Name());
		stream->print(" ");
		printVector(stream, accel);
		stream->print(", ");
		printVector(stream, mag);
		stream->print("\r\n");

		m_prevAccel = accel;
		m_prevMag = mag;
	}
}