#include "trialbero.h"

int main(){
    trialbero<int> tree;
    tree.insert(10);
    tree.insert(100);
    tree.insert(1000);
    std::cout << tree << std::endl;

    return 0;
}