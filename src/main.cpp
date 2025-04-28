#include <iostream>
#include "../include/utils.h"

int main(){
    int x = 4, y = 3;
    std::cout << "Add: " << MathUtils::add(x, y) << std::endl;
    std::cout << "Multiply: " << MathUtils::multiply(x, y) << std::endl;
    return 0;
}
