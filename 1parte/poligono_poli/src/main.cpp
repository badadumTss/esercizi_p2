#include "headers/*"
#include <iostream>

int main(){
	
	point pr[4];
	
	for (int i=0; i<4; i++){
		std::cout << "Inserire le coordinate di p" << i << "> ";
		double x,y,z;
		std::cin >> x >> y >> z;
		p[i] = punto(x,y,z);
	}

	rettangolo r1(p);

	point pt[3];

	for (int i=0; i<3; i++){			
		std::cout << "Inserire le coordinate di p" << i << "> ";
		double x,y,z;
		std::cin >> x >> y >> z;
		p[i] = punto(x,y,z);
	}
}

