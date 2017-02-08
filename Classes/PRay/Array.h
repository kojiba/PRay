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

        Array(RArray *array) {
            implementation = array;
        }

        virtual ~Array() {
            deleter(implementation, RArray);
            implementation = (RArray*)nil;
        }

        size_t count() {
            return implementation->count;
        }

        bool isEmpty() {
            return implementation->count > 0;
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

        size_t indexOf(Object *object) {
            return indexOfObjectRArray(implementation, object);
        }

        void append(Object *object) {
            object->retain();
            addObjectRArray(implementation, object);
        }

        void remove(Object* object) {
            deleteObjectRArray(implementation, object);
        }

        void removeFast(Object* object) {
            deleteObjectFastRArray(implementation, object);
        }

        void remove(size_t index) {
            deleteObjectAtIndexRArray(implementation, index);
        }

        void removeFast(size_t index) {
            deleteObjectAtIndexFastRArray(implementation, index);
        }

        void remove(RRange range) {
            deleteObjectsRArray(implementation, range);
        }

        Array array(RRange range) {
            return Array(getSubarrayRArray(implementation, range));
        }

        void useAutoCount() {
            implementation->destructorDelegate = (DestructorDelegate) Object::Deleter;
        }
    };
};

#endif /*__PRAYFOUNDATION_ARRAY_H__*/
