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
    let someConst = new String("some");

    (*array).append(someConst);
    (*array).append(new String("fix email"));
    (*array).append(new String("fix email 2"));

    var second = new String("Second");

    (*array).append(second);
    (*array).print();

    (*array).remove(second);
    (*array).print();

    var newArray = Value<Array>();
    (*newArray).append(someConst);

    someConst->rayPrint(); // refcount 2


    return 0;
}