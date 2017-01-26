/**
 * RayFoundation.h
 * A ray of light in the realm of darkness.
 * Some additions to C.
 * If You don't like it, You can preprocess files, to get pure-C code.
 * Author Kucheruavyu Ilya (kojiba@protonmail.com)
 * 2014 Ukraine Kharkiv
 *  _         _ _ _
 * | |       (_|_) |
 * | | _____  _ _| |__   __ _
 * | |/ / _ \| | | '_ \ / _` |
 * |   " (_) | | | |_) | (_| |
 * |_|\_\___/| |_|_.__/ \__,_|
 *          _/ |
 *         |__/
 **/

#ifndef __RAY_FOUNDATION__
#define __RAY_FOUNDATION__

#ifdef  __cplusplus
extern "C" {
#endif

// Workers
#include "RSystem.h"
#include "RSyntax.h"
#include "RColors.h"
#include "RayFoundation/RBasics/RBasics.h"
#include "RayFoundation/RClassTable/RClassTable.h"

// Containers
#include "RayFoundation/RContainers/RArray.h"
#include "RayFoundation/RContainers/RArray_Blocks.h"
#include "RayFoundation/RContainers/RArray_Parallel.h"
#include "RayFoundation/RContainers/RList.h"
#include "RayFoundation/RContainers/RBuffer.h"
#include "RayFoundation/RContainers/RDictionary.h"

// Strings
#include "RayFoundation/RString/RString.h"
#include "RayFoundation/RString/RString_Char.h"
#include "RayFoundation/RString/RString_Numbers.h"
#include "RayFoundation/RString/RString_UTF8.h"
#include "RayFoundation/RString/RString_Consts.h"
#include "RayFoundation/RString/RString_File.h"

// Memory operations
#include "RayFoundation/RMemoryOperations/RByteOperations.h"
#include "RayFoundation/RMemoryOperations/RData.h"
#include "RayFoundation/RMemoryOperations/RSandBox.h"
#include "RayFoundation/RMemoryOperations/RAutoPool.h"

// Encoding
#include "RayFoundation/REncoding/RBase64.h"
#include "RayFoundation/REncoding/PurgeEvasionUtilsRay.h"

// Networking
#include "RayFoundation/RNetwork/RSocket.h"
#include "RayFoundation/RNetwork/RTCPHandler.h"

// Threads
#include "RayFoundation/RThread/RThread.h"
#include "RayFoundation/RThread/RThreadPool.h"

// Others
#include "RayFoundation/Utils/Utils.h"
#include "RayFoundation/Utils/PurgeEvasionConnection.h"
#include "RayFoundation/Utils/PurgeEvasionParallel.h"
#include "RayFoundation/Utils/PurgeEvasionTCPHandler.h"

#ifdef RAY_BLOCKS_ON
#define endRay() deleter(stringConstantsTable(), RDictionary);\
                 deleter(RCTSingleton, RClassTable); \
                 deleter(singleBlockPool(), RAutoPool); \
                 p(RAutoPool)(RPool); \
                 deleter(RPool, RAutoPool); \
                 stopConsole();\
                 return 0
#else
#define endRay() deleter(stringConstantsTable(), RDictionary);\
                 deleter(RCTSingleton, RClassTable); \
                 p(RAutoPool)(RPool); \
                 deleter(RPool, RAutoPool); \
                 stopConsole();\
                 return 0
#endif

#ifdef  __cplusplus
};
#endif

#endif /*__RAY_FOUNDATION__*/