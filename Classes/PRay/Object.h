//
// Created by kojiba on 30.01.17.
//

/**
 * Object.h
 * Author Kucheruavyu Ilya (kojiba@ro.ru)
 * 30.01.17 Ukraine Kharkiv
 *  _         _ _ _
 * | |       (_|_) |
 * | | _____  _ _| |__   __ _
 * | |/ / _ \| | | '_ \ / _` |
 * |   < (_) | | | |_) | (_| |
 * |_|\_\___/| |_|_.__/ \__,_|
 *          _/ |
 *         |__/
 **/

#ifndef __PRAYFOUNDATION_OBJECT_H__
#define __PRAYFOUNDATION_OBJECT_H__

#include <RayFoundation/RayFoundation.h>

namespace ray {

    class Object {
    protected:
        size_t referenceCount;

        virtual void dealloc() {
            printf("Dealloc for %p\n", this);
            delete this;
        }

    public:
        Object() {
            referenceCount = 0;
            RPrintf("C++ Object constructor %p\n", this);
        }

        virtual ~Object() {
            RPrintf("C++ Object destructor %p\n", this);
        }

        virtual void print() {

        }

        void retain() {
            ++referenceCount;
        }

        void release() {
            if (referenceCount > 0) {
                --referenceCount;
                if (referenceCount == 0) {
                    dealloc();
                }
                return;
            }
            dealloc();
        }

        static void Deleter(Object *object) {
            object->release();
        }

        static void Printer(Object *object) {
            object->print();
        }
    };
}

#endif /*__PRAYFOUNDATION_OBJECT_H__*/
