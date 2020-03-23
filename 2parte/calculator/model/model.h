#ifndef MODEL_H
#define MODEL_H
#include "hierachy/alu.h"
#include "hierachy/memory.h"
#include "hierachy/exeptions.h"

class model{
	alu* ALU;
	memory* MEMO;
public:
	model(alu* = nullptr,memory* = nullptr);
	~model();

	/* Memory methods */
	void memset(unsigned long ,int);
	int memget(unsigned long) const;

	/* Alu methods */
	void sum(int);
	void diff(int);
	void multiply(int);
	void divide(int);
	int getResult() const;
};

#endif /* MODEL_H */
