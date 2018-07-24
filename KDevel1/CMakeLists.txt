cmake_minimum_required(VERSION 2.6)
project(kdevel1)

add_executable(kdevel1 main.cpp)

install(TARGETS kdevel1 RUNTIME DESTINATION bin)
