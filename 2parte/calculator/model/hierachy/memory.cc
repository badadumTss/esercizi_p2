#include "memory.h"
#include "exeptions.h"

void memory::set(unsigned long reg, int value){
	if(reg < registries.size()) throw RegNotInit(reg);
	else registries[reg] = value;
	return;
}

int memory::get(unsigned long reg) const {
	return registries.at(reg);
}
