#include "classeC.h"

int main(int argc, char *argv[]){

    C <char,3> arr1('q',10);
    C <char,5> arr2('a',3);
    C <char,3> arr3(arr1);

    for(int i=0; i<argc; ++i){
	std::cout << argv[i] << std::endl;
    }
    *(arr1[2]) = *(argv[1]); 

    std::cout << arr1 << std::endl << arr2;
    
    if(arr3 == arr1){
	std::cout << "Uguali" << std::endl;
    } else std::cout << "Diversi" << std::endl;

    return 0;
}
