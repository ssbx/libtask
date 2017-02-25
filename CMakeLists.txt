cmake_minimum_required (VERSION 2.6)
project (libtask)

include_directories(.)

add_library(task
    386-ucontext.h
    amd64-ucontext.h
    mips-ucontext.h
    power-ucontext.h
    task.h
    taskimpl.h
    channel.c
    context.c
    fd.c
    httpload.c
    net.c
    primes.c
    print.c
    qlock.c
    rendez.c
    task.c)
