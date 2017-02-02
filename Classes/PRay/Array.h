/**
 * Object.h
 * Author Kucheruavyu Ilya (kojiba@ro.ru)
 * 26.01.17 Ukraine Kharkiv
 *  _         _ _ _
 * | |       (_|_) |
 * | | _____  _ _| |__   __ _
 * | |/ / _ \| | | '_ \ / _` |
 * |   < (_) | | | |_) | (_| |
 * |_|\_\___/| |_|_.__/ \__,_|
 *          _/ |
 *         |__/
 **/

#ifndef __PRAYFOUNDATION_ARRAY_H__
#define __PRAYFOUNDATION_ARRAY_H__

#import <PRay/Object.h>

namespace ray {

    class Array: public Object {
        RArray *implementation;

    public:
        Array() {
            implementation = c(RArray)((RArray *) nil, (RArrayFlags *) nil);
            implementation->printerDelegate = (PrinterDelegate) Object::Printer;
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
        }

        virtual ~Array() {
            deleter(implementation, RArray);
            implementation = (RArray*)nil;
        }

        void print() override {
            printShortRArray(implementation);
            printf("\n");
        }

        virtual void rayPrint() override {
            printf("ray::Array ");
            Object::rayPrint();
            p(RArray)(implementation);
        }

        void append(Object *object) {
            object->retain();
            addObjectRArray(implementation, object);
        }

        void remove(Object* object) {
            deleteObjectRArray(implementation, object);
        }

        void useAutoCount() {
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
        }
    };
};

#endif /*__PRAYFOUNDATION_ARRAY_H__*/
