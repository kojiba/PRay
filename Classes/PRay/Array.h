//
// Created by kojiba on 26.01.17.
//

#ifndef __PRAYFOUNDATION_ARRAY_H__
#define __PRAYFOUNDATION_ARRAY_H__

#include <RayFoundation/RayFoundation.h>

#define var auto

namespace ray {

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

    class Object {
        size_t referenceCount;
    protected:
        void release() {
            if (referenceCount > 0) {
                --referenceCount;

                } else {
                delete this;
            }
        }
    public:
        Object() {

        }

        virtual ~Object() {

        }

        virtual void print() {

        }

        void retain() {
            ++referenceCount;
        }

        static void Deleter(Object *object) {
            object->release();
        }

        static void Printer(Object *object) {
            object->print();
        }
    };

    class String : public Object {
        RString *implementation;
        rbool isConst;
        rbool isWeak;

    public:
        String() {
            implementation = (RString *) RS("");
            isConst = yes;
            isWeak = no;
        }

        String(char *string) {
            implementation = $((RString*)allocator(RData), m(setConstantString, RString)), string);
            isConst = no;
            isWeak = yes;
        }

        ~String() override {
            if (!isConst && !isWeak) {
                deleter(implementation, RString);
            }
            if (isWeak) {
                deallocator(implementation);
            }
        }

        void print() override {
            p(RString)(implementation);
        }
    };

    class Array {
        RArray *implementation;

    public:
        Array() {
            implementation = c(RArray)((RArray *) nil, (RArrayFlags *) nil);
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
            implementation->printerDelegate = (PrinterDelegate) Object::Printer;
        }

        ~Array() {
            deleter(implementation, RArray);
        }

        void print() {
            p(RArray)(implementation);
        }

        void append(Object &object) {
            object.retain();
            addObjectRArray(implementation, &object);
        }
    };
};

#endif /*__PRAYFOUNDATION_ARRAY_H__*/
