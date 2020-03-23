#include "exeptions.h"

exeption::exeption(std::string desc):description(desc){}

std::string exeption::getDescription() const {
	return description;
}

RegNotInit::RegNotInit(int r):exeption("Register not initialized: "),reg(r){}

std::string RegNotInit::getDescription() const {
	return exeption::getDescription() + "register " + std::to_string(reg);
}


InvalidExpr::InvalidExpr(std::string str):exeption("Invalid expression: "),expr(str){}

std::string InvalidExpr::getDescription() const {
    return exeption::getDescription() + expr;
}
