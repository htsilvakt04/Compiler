cmake_minimum_required(VERSION 4.3)
project(clox C)

set(CMAKE_C_STANDARD 11)

add_executable(clox
        main.c
        common.h
        chunk.h
        chunk.c
        memory.h
        memory.c
        debug.h
        debug.c
        value.c
        value.h
        vm.h
        vm.c
        compiler.h
        compiler.c
        scanner.c
        scanner.h
        object.h
        object.c)
