cmake_minimum_required (VERSION 2.6)
project (libtask)

include_directories(code)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Makefile.in
    ${CMAKE_CURRENT_SOURCE_DIR}/Makefile)

add_library(task
    code/386-ucontext.h
    code/amd64-ucontext.h
    code/mips-ucontext.h
    code/power-ucontext.h
    code/task.h
    code/taskimpl.h
    code/channel.c
    code/context.c
    code/fd.c
    code/httpload.c
    code/net.c
    code/primes.c
    code/print.c
    code/qlock.c
    code/rendez.c
    code/task.c)
