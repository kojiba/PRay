#include <iostream>
#include "RayFoundation/RayFoundation.h"
#include <PRay/Array.h>
#include <PRay/String.h>

using namespace ray;

#define var auto

class RayFoundation {
public:

    RayFoundation() {
        enablePool(RPool);
        RPrintSystemInfo();
    }

    ~RayFoundation() {

        deleter(stringConstantsTable(), RDictionary);
        deleter(RCTSingleton, RClassTable);
        p(RAutoPool)(RPool);
        deleter(RPool, RAutoPool);
    }
};

int main() {
    var foundation = RayFoundation();

    var array = Array();

    var string = new String("some");

    array.append(string);

    var second = new String("Second");
    array.append(second);

    array.print();

    array.release();

    return 0;
}