#include<iostream>
#include "missile.h"

int main(){
    missile NASA(3,10,4);
	std::cout << "Superficie laterale = " << NASA.superficie_laterale() << std::endl <<
		"Volume = " << NASA.volume() << std::endl <<
		"Area laterale = " << NASA.area_tot() << std::endl;
    return 0;
}
