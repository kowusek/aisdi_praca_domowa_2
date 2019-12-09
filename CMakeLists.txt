cmake_minimum_required(VERSION 3.15)
project(cards)

set(CMAKE_CXX_STANDARD 11)

add_executable(cards main.cpp deck.cpp deck.h)