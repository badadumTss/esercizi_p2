#include "model.h"

model::model(alu* current_alu, memory* current_memory):
	ALU(current_alu ? new alu(*current_alu) : new alu()),
	MEMO(current_memory ? new memory(*current_memory) : new memory()){}

model::~model(){ delete ALU; delete MEMO; }

void model::memset(unsigned long reg, int value){ MEMO->set(reg,value); }
int model::memget(unsigned long reg) const { return MEMO->get(reg); }

void model::sum(int val) { ALU->sum(val); };
void model::diff(int val) { ALU->diff(val); };
void model::multiply(int val){ ALU->multiply(val); };
void model::divide(int val) { ALU->divide(val); };

int model::getResult() const { return ALU->getResult(); };
