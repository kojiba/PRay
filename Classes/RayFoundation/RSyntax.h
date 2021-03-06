/**
 * RSyntax.h
 * A ray of light in the realm of darkness.
 * Some syntax additions to C.
 * If You don't like it,
 * You can preprocess file, to get pure-C code.
 * Author Kucheruavyu Ilya (kojiba@protonmail.com)
 * 2014 Ukraine Kharkiv
 *  _         _ _ _
 * | |       (_|_) |
 * | | _____  _ _| |__   __ _
 * | |/ / _ \| | | '_ \ / _` |
 * |   < (_) | | | |_) | (_| |
 * |_|\_\___/| |_|_.__/ \__,_|
 *          _/ |
 *         |__/
 **/

#ifndef __R_SYNTAX_H__
#define __R_SYNTAX_H__

#include "RayCheckFoundation.h"
#include "RColors.h"
#include "RayBase.h"
#include "RErrors.h"

// working defines
#define _TOSTRING(x)                                      #x
#define toString(x)                                       _TOSTRING(x)        // gets c-string from define or some code

#define _concatenate(one, two)                            one##two
#define concatenate(one, two)                             _concatenate(one, two)  // concatenate two words: concatenate(Hello, World) -> HelloWorld

#define initRClock()                                      clock_t tic = clock(); \
                                                          clock_t diff = 0, toc = 0;

#define tickRClock()                                      toc = clock(); \
                                                          diff = toc - tic; \
                                                          tic = clock(); \
                                                          RPrintf("Elapsed: %f seconds\n", (double)(diff) / CLOCKS_PER_SEC);

#define RAY_TEST(conditionZero, message, errorCode)       if(conditionZero) { \
                                                              RFPrintf(stderr, "ERROR. TESTS. " message "\n"); \
                                                              return errorCode;\
                                                          }

#define RPrintLn(string)                                  RPrintf("%s\n", string)

// typedefs
typedef void*   pointer;

#ifdef _WIN32
    #warning Undefine windows 'byte' typedef
    #undef byte
#endif
typedef uint8_t  byte;
typedef uint16_t u16;

typedef byte    rbool;
#define yes                                               ((rbool)   1)
#define no                                                ((rbool)   0)
#define nil                                               ((pointer) 0)

#define allocator(className)                              RAlloc(sizeof(className))
#define arrayAllocator(className, size)                   RAlloc(sizeof(className) * (size))
#define arraySize(className, size)                        (sizeof(className) * (size))
#define deallocator(object)                               RFree(object)

// calls
#define c(className)                                      concatenate(constructorOf, className)                                       // constructor function name
#define d(className)                                      concatenate(destructorOf,  className)                                       // destructor function name
#define p(className)                                      concatenate(printerOf,     className)                                       // printer function name
#define m(methodName, className)                          concatenate(methodName,    className) // concatenate(concatenate(className, _), methodName) // some method function name
#define sm(methodName, className)                         concatenate(concatenate(staticMethod,methodName),concatenate(Of,className)) // static method function name
#define master(object, masterClassName)                   object->concatenate(master,concatenate(masterClassName, Object))            // call to masterClassObject
#define singletonCall(className)                          concatenate(singletonOf,className)()                                        // singleton call
#define deleter(object, className)                        $(object, d(className))); deallocator(object)
#define nilDeleter(object, className)                     if(object != nil) { deleter(object, className); }                            // fast check if not nil -> delete
#define deleterName(className)                            concatenate(className,Deleter)

// declarations
#define class(className)                                  typedef struct className { \
                                                          size_t classId;
#define protocol(protocolName)                            typedef struct protocolName { \
                                                          pointer context;

#define discipleOf(className)                             className *concatenate(master, concatenate(className, Object));
#define endOf(className)                                  } className;

#define method(returnValue, methodName, className)        returnValue m(methodName, className)(className *object
#define constMethod(returnValue, methodName, className)   returnValue m(methodName, className)(const className *const object

#define constructor(className)                            className* c(className)(className *object
#define destructor(className)                             void d(className)(className *object)
#define printer(className)                                void p(className)(className *object)
#define generateDeleter(className)                        void deleterName(className)(className *object) { deleter(object, className); }

#define singleton(className)                              className* singletonCall(className)
#define staticMethod(returnValue, methodName, className)  returnValue sm(methodName, className)(className *deprecatedObject
#define virtualMethod(returnValue, methodName)            returnValue (*methodName)
#define linkMethod(object, virtualName, realName)         object->virtualName = realName;


#define setter(propertyName, propertyType, className)     method(void, concatenate(set_, propertyName), className), propertyType toSet)
#define getter(propertyName, propertyType, className)     method(propertyType, concatenate(get_, propertyName), className))

#define setterImpl(propertyName, propertyType, className) setter(propertyName, propertyType, className) { object->propertyName = toSet; }
#define getterImpl(propertyName, propertyType, className) getter(propertyName, propertyType, className) { return object->propertyName; }

#define setterImplMutex(propertyName, propertyType,\
                        className, mutex)                setter(propertyName, propertyType, className) { RMutexLock(mutex); object->propertyName = toSet; RMutexUnlock(mutex);}

#define $(object, methodName)                             methodName(object

// cases/if/for ...
#define forAll(iterator, count)                           for(iterator = 0; iterator < (count); ++iterator)
#define fromStartForAll(iterator, start, count)           for(iterator = start; iterator < (start) + (count); ++iterator)
#define inRange(iterator, RRange)                         for(iterator = RRange.start; iterator < RRange.start + RRange.size; ++iterator)

#endif /*__R_SYNTAX_H__*/
