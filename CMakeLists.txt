cmake_minimum_required(VERSION 3.6)
project(PrayFoundation)

set(CMAKE_CXX_STANDARD 11)

include_directories(Classes)
include_directories(PRay)

file(GLOB_RECURSE SRCS  Classes/*.cpp)
file(GLOB_RECURSE HDRS  Classes/*.h)
file(GLOB_RECURSE CSRCS Classes/*.c)

add_executable(PrayFoundation ${SRCS} ${HDRS} ${CSRCS})