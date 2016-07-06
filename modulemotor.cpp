#include "modulemotor.h"

void ModuleMotor::Init(int chan) {
	SetChannel(chan);
}

void ModuleMotor::Set(int* params, int paramc) {
	if (paramc == 1) {
		SetMotor(params[0]);
	}
}
