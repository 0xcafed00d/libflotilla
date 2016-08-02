#include "module.h"

Module::Module() : m_connected(true) {
}

void Module::SetChannel(int c) {
	m_channel = c;
}

void Module::printUpdateHeader(SerialStream* stream) {
	stream->print("u ");
	stream->print(Channel());
	stream->print("/");
	stream->print(Name());
	stream->print(" ");
}

void Module::printList(SerialStream* stream, int a) {
	stream->print(a);
	stream->print("\r\n");
}

void Module::printList(SerialStream* stream, int a, int b) {
	stream->print(a);
	stream->print(",");
	printList(stream, b);
}

void Module::printList(SerialStream* stream, int a, int b, int c) {
	stream->print(a);
	stream->print(",");
	printList(stream, b, c);
}

void Module::printList(SerialStream* stream, int a, int b, int c, int d) {
	stream->print(a);
	stream->print(",");
	printList(stream, b, c, d);
}

int Module::Channel() {
	return m_channel;
}

bool Module::IsConnected() {
	return m_connected;
}

void Module::SetConnected(bool c) {
	m_connected = c;
}

void Module::OnEnquire(SerialStream* stream) {
	stream->print("c ");
	stream->print(Channel());
	stream->print("/");
	stream->print(Name());
	stream->print("\r\n");
}

void Module::Set(int*, int) {
}

void Module::Update(SerialStream*) {
}
