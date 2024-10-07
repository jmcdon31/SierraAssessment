cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER "g++-11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror -O2")

project(SierraSpaceAssessment)

add_executable(SierraSpaceAssessment
   Main.cpp
   CommandProcessor.cpp
   AttitudeControl.cpp
   AttitudeControlMotor.cpp
   AttitudeSensor.cpp
   MockSpaceAxis.cpp
   )

include_directories(include)
