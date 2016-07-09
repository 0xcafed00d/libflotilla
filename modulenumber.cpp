#include "modulenumber.h"

void ModuleNumber::Init(int chan) {
	SetChannel(chan);
}

void ModuleNumber::Set(int* params, int paramc) {
	uint8_t data[4];
	bool colon = false;
	bool apostrophe = false;

	if (paramc >= 4 && paramc <= 6) {
		for (int n = 0; n < 4; n++) {
			data[n] = (uint8_t)params[n];
		}
		if (paramc >= 5) {
			colon = (bool)params[4];
		}
		if (paramc == 6) {
			colon = (bool)params[5];
		}
		this->SetNumber(data, colon, apostrophe);
	}
}
