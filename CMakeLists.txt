cmake_minimum_required(VERSION 3.17)
project(Error_Correction_and_Detection_Codes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Error_Correction_and_Detection_Codes main.cpp Paridad.cpp Paridad.h Redundancia_ciclica.cpp Redundancia_ciclica.h Hamming.cpp Hamming.h)