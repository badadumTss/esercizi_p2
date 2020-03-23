#ifndef ALU_H
#define ALU_H

class alu{
	int Accumulator;	
public:
	alu();
	void sum(int);
	void diff(int);
	void divide(int);
	void multiply(int);
	int getResult() const;
};

#endif /* ALU_H */
