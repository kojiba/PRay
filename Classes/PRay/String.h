//
// Created by kojiba on 30.01.17.
//

/**
 * String.h
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

#ifndef __PRAYFOUNDATION_STRING_H__
#define __PRAYFOUNDATION_STRING_H__

#include <PRay/Object.h>

namespace ray {

    class String : public Object {
        RString *implementation;
        rbool isConst;
        rbool isWeak;

    protected:
        void dealloc() override {
            if (!isConst && !isWeak) {
                deleter(implementation, RString);
            }
            if (isWeak) {
                deallocator(implementation);
            }
            Object::dealloc();
        }

    public:
        String() : Object() {
            implementation = (RString *) RS("");
            isConst = yes;
            isWeak = no;
        }

        String(char *string) : Object() {
            implementation = $((RString *) allocator(RData), m(setConstantString, RString)), string);
            isConst = no;
            isWeak = yes;
        }

        ~String() {

        }

        void print() override {
            p(RString)(implementation);
        }
    };
};


#endif /*__PRAYFOUNDATION_STRING_H__*/
