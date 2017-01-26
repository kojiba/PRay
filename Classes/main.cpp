#include <iostream>
#include "RayFoundation/RayFoundation.h"

printer(RArray);

int main() {
    RArray *array = constructorOfRArray((RArray*)nil, (RArrayFlags*)nil);
    addObjectRArray(array, (pointer) 1);
    printerOfRArray(array);
    deleter(array, RArray);
    std::cout << "https://github.com/kojiba/PRay" << std::endl;
    return 0;
}