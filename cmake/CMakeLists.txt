cmake_minimum_required(VERSION 3.16.3)
project("Hello World")

add_subdirectory(libhello)

set(SRC "main.cc")

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")

add_executable(hello ${SRC})

target_link_libraries(hello PUBLIC libhello)