#include "modulematrix.h"

void ModuleMatrix::Init(int chan) {
	SetChannel(chan);
	OnInit();
}

void ModuleMatrix::Set(int* params, int paramc) {
	uint8_t data[8];

	if (paramc == 9) {
		for (int n = 0; n < 8; n++) {
			data[n] = (uint8_t)params[n];
		}
		this->SetMatrix(data, (uint8_t)params[8]);
	}
}
