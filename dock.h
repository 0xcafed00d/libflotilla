#ifndef ARDUINO_FLOTILLA_DOCK_H
#define ARDUINO_FLOTILLA_DOCK_H

#include "module.h"

class Dock {
  private:
	static const size_t BUFFER_SZ = 128;
	static const size_t NUM_MODULES = 8;
	TimerUtil* m_timerutil;
	PersistantStore* m_store;

	char m_inputBuffer[BUFFER_SZ + 1];
	size_t m_bufferPos;
	char* m_tokenPtrs[32];
	Module* m_channels[NUM_MODULES];

	TimeOut m_fpsTimer;
	long m_fpsCounter;
	long m_fps;

	TimeOut m_updateTimer;

	void handleBuffer(SerialStream* stream);
	void parseBuffer();
	int convertParams(char** params, int* intParams);

	void handleCommand(char** cmd, SerialStream* stream);
	void handleVersion(SerialStream* stream);
	void handleDebug(SerialStream* stream);
	void handleEnquire(SerialStream* stream);
	void handleSet(char** params);
	void handleName(char** params);

  public:
	Dock(TimerUtil* timerutil, PersistantStore* store);
	void AddModule(Module* mod);
	void ProcessInput(SerialStream* stream);
	void Update(SerialStream* stream);
};

#endif
