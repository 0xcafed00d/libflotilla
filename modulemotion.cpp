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

	m_accel.x.addValue(accel.x);
	m_accel.y.addValue(accel.y);
	m_accel.z.addValue(accel.z);
	m_mag.x.addValue(accel.x);
	m_mag.y.addValue(accel.y);
	m_mag.z.addValue(accel.z);

	if (m_timeout.hasTimedOut()) {
		accel.x = m_accel.x.value();
		accel.y = m_accel.y.value();
		accel.z = m_accel.z.value();
		mag.x = m_mag.x.value();
		mag.y = m_mag.y.value();
		mag.z = m_mag.z.value();

		if (accel != m_prevAccel || mag != m_prevMag) {
			printUpdateHeader(stream);
			printVector(stream, accel);
			stream->print(", ");
			printVector(stream, mag);
			stream->print("\r\n");

			m_prevAccel = accel;
			m_prevMag = mag;
			m_timeout = TimeOut(100);
		}
		m_accel.x.reset();
		m_accel.y.reset();
		m_accel.z.reset();
		m_mag.x.reset();
		m_mag.y.reset();
		m_mag.z.reset();
	}
}