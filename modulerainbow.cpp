#include "modulerainbow.h"

void ModuleRainbow::Init(int chan) {
	SetChannel(chan);
}

void ModuleRainbow::Set(int* params, int paramc) {
	if (paramc == 15) {
		for (int n = 0; n < 5; n++) {
			this->SetLED(n, params[n * 3], params[n * 3 + 1], params[n * 3 + 2]);
		}
	} else if (paramc == 3) {
		for (int n = 0; n < 5; n++) {
			this->SetLED(n, params[0], params[1], params[2]);
		}
	}
}
