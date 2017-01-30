#include <iostream>
#include "RayFoundation/RayFoundation.h"
#include <PRay/Array.h>

using namespace ray;

int main() {
    var foundation = RayFoundation();

    var array = Array();

    var string = String("some");

    array.append(string);
    array.print();

    return 0;
}