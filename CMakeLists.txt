cmake_minimum_required(VERSION 3.12)
project(3011)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)
include_directories(libmtm)
include_directories(uniqueOrderedList)

add_executable(3011
        libmtm/libmtm.a
        libmtm/set.h
        uniqueOrderedList/UniqueOrderedList.c
        uniqueOrderedList/uniqueOrderedList.h
        citizen.c
        citizen.h
        list.h
        main.c
        mtm_elections.h
        mtm_print.c
        mtm_print.h
        City.h
        City.c
        typedefs_and_general_functions.c
        typedefs_and_general_functions.h preference.c preference.h Candidate.h Candidate.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic-errors -Werror")