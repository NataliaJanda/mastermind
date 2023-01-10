cmake_minimum_required(VERSION 3.24)
project(mastermind)

set(CMAKE_CXX_STANDARD 17)

add_executable(mastermind main.cpp game.cpp game.h play.cpp play.h ObslugaMenu.cpp ObslugaMenu.h)

set(CMAKE_EXE_LINKER_FLAGS "-static")