cmake_minimum_required(VERSION 3.14)
project(MyC)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyC jichu.c a.cpp file.c my.c)

#file(GLOB source_path C:/Work/CLionProjects/MyC/*.c C:/Work/CLionProjects/MyC/*.cpp)
add_library(file SHARED file.c)#SHARED 表示是动态库
#add_subdirectory(./jniLibs/armeabi-v7a)

#add_library(jinInterface STATIC file.c file.h)#STATIC 表示是静态库
#ADD_LIBRARY(libfile [SHARED] )