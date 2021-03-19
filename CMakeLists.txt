cmake_minimum_required(VERSION 3.17)
project(PSS_as)

set(CMAKE_CXX_STANDARD 14)

add_executable(PSS_as main.cpp Users/Person.cpp Users/Person.h Users/Student.cpp Users/Student.h Users/Professor.cpp Users/Professor.h Users/lab_employees.cpp Users/lab_employees.h Users/Admin.cpp Users/Admin.h University.cpp University.h Room.cpp Room.h Users/Guest.cpp Users/Guest.h)