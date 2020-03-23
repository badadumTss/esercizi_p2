#ifndef EXEPTIONS_H
#define EXEPTIONS_H
#include <string>

class exeption{
	std::string description;
public:
	virtual ~exeption() = default;
	exeption(std::string);
	virtual std::string getDescription() const;
};

class RegNotInit: public exeption{
	int reg; 
public:
	RegNotInit(int);
	std::string getDescription() const;
};

class InvalidExpr: public exeption{
    std::string expr;
public:
    InvalidExpr(std::string);
    std::string getDescription() const;
};

#endif /* EXEPTIONS_H */
