#include "module.h"

Module::Module() : m_connected(true) {
}

void Module::SetChannel(int c) {
	m_channel = c;
}

void Module::printUpdateHeader(Stream* stream) {
	stream->print("u ");
	stream->print(Channel());
	stream->print("/");
	stream->print(Name());
	stream->print(" ");
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

void Module::OnEnquire(Stream* stream) {
	stream->print("c ");
	stream->print(Channel());
	stream->print("/");
	stream->print(Name());
	stream->print("\r\n");
}

void Module::Set(int* params, int paramc) {
}

void Module::Update(Stream* stream) {
}
