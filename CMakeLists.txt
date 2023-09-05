cmake_minimum_required(VERSION 3.27.4)

project("Md4" LANGUAGES CXX)
add_executable(main md4_o.cpp rand.cpp stream.cpp util.cpp)
target_include_directories(main PRIVATE .)