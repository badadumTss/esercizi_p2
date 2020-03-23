#include "alu.h"

alu::alu():Accumulator(0){}

void alu::sum(int a){
	Accumulator += a;
}

void alu::diff(int a){
	Accumulator -= a;
}

void alu::multiply(int a){
	Accumulator *= a;
}

void alu::divide(int a){
	Accumulator /= a;
}

int alu::getResult() const {
	return Accumulator;
}
