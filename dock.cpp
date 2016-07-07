#include "dock.h"
#include "eepromutils.h"

bool isDelim(char c) {
	return c == ',' || c == ' ';
}

Dock::Dock() : m_bufferPos(0), m_fpsTimer(1000), m_fpsCounter(0), m_fps(0), m_updateTimer(50) {
	memset(m_channels, 0, sizeof(m_channels));
}

int Dock::convertParams(char** params, int* intParams) {
	int pcount = 0;
	while (*params) {
		intParams[pcount++] = atoi(*params++);
	}
	return pcount;
}

void Dock::handleSet(char** params, Stream* stream) {
	int intParams[16];

	int pcount = convertParams(params, intParams);
	if (pcount > 1) {
		Module* m = m_channels[intParams[0] - 1];
		if (m && m->IsConnected()) {
			m->Set(intParams + 1, pcount - 1);
		}
	}
}

void Dock::handleCommand(char** cmd, Stream* stream) {
	if (*cmd) {
		switch (*cmd[0]) {
			case 'v':
				handleVersion(stream);
				break;
			case 'd':
				handleDebug(stream);
				break;
			case 'e':
				handleEnquire(stream);
				break;
			case 's':
				handleSet(cmd + 1, stream);
				break;
			case 'n':
				handleName(cmd + 1, stream);
				break;
		}
	}
}

struct flotillaName {
	char name[9];
	uint8_t check;
};

void writeName(const char* name, size_t index) {
	flotillaName fname;
	memset(&fname, 0, sizeof(fname));
	strncpy(fname.name, name, 8);
	fname.check = checksum(&fname);
	writeStructEEPROM(fname, sizeof(fname) * index);
}

void readName(char* name, size_t index) {
	flotillaName fname;
	readStructEEPROM(fname, sizeof(fname) * index);
	uint8_t chk = fname.check;
	fname.check = 0;

	if (chk == checksum(&fname)) {
		strcpy(name, fname.name);
	} else {
		strcpy(name, "Unnamed");
	}
}

void Dock::handleName(char** params, Stream* stream) {
	if (*params) {
		if (*params[0] == 'u') {
			writeName(params[1], 0);
		}
		if (*params[0] == 'd') {
			writeName(params[1], 1);
		}
	}
}

void Dock::parseBuffer() {
	char** toks = m_tokenPtrs;
	*toks = NULL;

	if (m_bufferPos > 0 && !isDelim(m_inputBuffer[0])) {
		*toks++ = m_inputBuffer;
		for (size_t n = 1; n < m_bufferPos; n++) {
			if (isDelim(m_inputBuffer[n])) {
				m_inputBuffer[n] = 0;
			} else {
				if (m_inputBuffer[n - 1] == 0) {
					*toks++ = m_inputBuffer + n;
				}
			}
		}
	}
	*toks = NULL;
}

void Dock::handleVersion(Stream* stream) {
	char name[9];
	stream->print("# Flotilla ready to set sail..\r\n");
	stream->print("# Version: 1.12\r\n");
	stream->print("# Serial: 0111111111111111111111\r\n");

	readName(name, 0);
	stream->print("# User: ");
	stream->print(name);

	readName(name, 1);
	stream->print("\r\n# Dock: ");
	stream->print(name);
	stream->print("\r\n");
}

void Dock::handleDebug(Stream* stream) {
	stream->print("# SRAM: 1337 bytes\r\n");
	long us = 1000000 / m_fps;
	stream->print("# Loop: ");
	stream->print(us / 1000);
	stream->print("ms (");
	stream->print(us);
	stream->print("0us) ");
	stream->print(m_fps);
	stream->print("fps\r\n");
	stream->print("# Channels:\r\n");
	for (size_t n = 0; n < NUM_MODULES; n++) {
		stream->print("# - ");
		stream->print(n);
		if (m_channels[n] != NULL) {
			stream->print("/");
			stream->print(m_channels[n]->Name());
		}
		stream->print("\r\n");
	}
}

void Dock::handleEnquire(Stream* stream) {
	for (size_t n = 0; n < NUM_MODULES; n++) {
		if (m_channels[n] != NULL) {
			m_channels[n]->OnEnquire(stream);
		}
	}
}

void Dock::handleBuffer(Stream* stream) {
	m_inputBuffer[m_bufferPos] = 0;
	parseBuffer();
	handleCommand(m_tokenPtrs, stream);
	m_bufferPos = 0;
}

void Dock::AddModule(Module* mod) {
	int chan = mod->Channel();

	m_channels[chan - 1] = mod;
}

void Dock::ProcessInput(Stream* stream) {
	m_fpsCounter++;
	if (m_fpsTimer.hasTimedOut()) {
		m_fps = m_fpsCounter;
		m_fpsCounter = 0;
		m_fpsTimer = TimeOut(1000);
	}

	while (true) {
		int c = stream->read();
		if (c == -1)
			break;

		switch (c) {
			case '\r':
				handleBuffer(stream);
				break;
			case '\n':
				break;
			default:
				m_inputBuffer[m_bufferPos++] = (char)c;
		}
	}
}

void Dock::Update(Stream* stream) {
	if (m_updateTimer.hasTimedOut()) {
		for (size_t n = 0; n < NUM_MODULES; n++) {
			if (m_channels[n] != NULL && m_channels[n]->IsConnected()) {
				m_channels[n]->Update(stream);
			}
		}
		m_updateTimer = TimeOut(50);
	}
}
