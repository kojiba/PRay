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

    public:
        String() : Object() {
            implementation = (RString *) RS("");
            isConst = yes;
            isWeak = no;
        }

        String(const char *string) : Object() {
            implementation = $((RString *) allocator(RData), m(setConstantString, RString)), string);
            isConst = no;
            isWeak = yes;
        }

        virtual ~String() {
            if (!isConst && !isWeak) {
                deleter(implementation, RString);
            }
            if (isWeak) {
                deallocator(implementation);
            }
        }

        void print() override {
            printInFileRData(implementation, stdout, no);
        }
    };
};


#endif /*__PRAYFOUNDATION_STRING_H__*/
