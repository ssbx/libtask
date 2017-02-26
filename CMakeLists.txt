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
    code/net.c
    code/print.c
    code/qlock.c
    code/rendez.c
    code/task.c)

add_executable(httpload code/impl/httpload.c)
add_executable(primes code/impl/primes.c)
add_executable(tcpproxy code/impl/tcpproxy.c)
add_executable(testdelay1 code/impl/testdelay1.c)
add_executable(testdelay code/impl/testdelay.c)
target_link_libraries(httpload task)
target_link_libraries(primes task)
target_link_libraries(tcpproxy task)
target_link_libraries(testdelay1 task)
target_link_libraries(testdelay task)
