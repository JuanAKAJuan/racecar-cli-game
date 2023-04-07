cmake_minimum_required(VERSION 3.24)
project(Course_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Course_Project main.cpp Racetrack.cpp Racetrack.h RaceCars.cpp RaceCars.h UserCar.cpp UserCar.h CPUSpeedCar.cpp CPUSpeedCar.h CPUHandleCar.cpp CPUHandleCar.h Application.cpp Application.h)
