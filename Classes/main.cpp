#include <iostream>
#include "RayFoundation/RayFoundation.h"
#include <PRay/Array.h>
#include <PRay/String.h>

using namespace ray;

#define var auto
#define let const var

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

    var array = Value<Array>();

    (*array).append(new String("some"));
    (*array).append(new String("fix email"));

    var second = new String("Second");

    (*array).append(second);
    (*array).print();

    (*array).remove(second);
    (*array).print();


    return 0;
}