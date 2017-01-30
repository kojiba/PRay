//
// Created by kojiba on 26.01.17.
//

#ifndef __PRAYFOUNDATION_ARRAY_H__
#define __PRAYFOUNDATION_ARRAY_H__

#import <PRay/Object.h>

namespace ray {

    class Array: public Object {
        RArray *implementation;

    protected:
        void dealloc() override {
            deleter(implementation, RArray);
        }

    public:
        Array() {
            RPrintf("C++ Array constructor %p\n", this);
            implementation = c(RArray)((RArray *) nil, (RArrayFlags *) nil);
            implementation->printerDelegate = (PrinterDelegate) Object::Printer;
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
        }

        ~Array() {
            RPrintf("C++ Array destructor %p\n", this);
        }

        void print() override {
            p(RArray)(implementation);
        }

        void append(Object *object) {
            object->retain();
            printf("add object %p\n", object);
            addObjectRArray(implementation, object);
        }

        void append(Object &object) {
            object.retain();
            printf("add object %p\n", &object);
            addObjectRArray(implementation, &object);
        }

        void useAutoCount() {
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
        }
    };
};

#endif /*__PRAYFOUNDATION_ARRAY_H__*/
