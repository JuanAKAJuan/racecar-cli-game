cmake_minimum_required(VERSION 3.22)
project(Course_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Course_Project main.cpp Racetrack.cpp Racetrack.h RaceCars.cpp RaceCars.h UserCar.cpp UserCar.h CPUSpeedCar.cpp CPUSpeedCar.h CPUHandleCar.cpp CPUHandleCar.h Application.cpp Application.h)

configure_file(tracks/track1.txt ${CMAKE_CURRENT_BINARY_DIR}/track1.txt COPYONLY)
configure_file(tracks/track2.txt ${CMAKE_CURRENT_BINARY_DIR}/track2.txt COPYONLY)
configure_file(tracks/track3.txt ${CMAKE_CURRENT_BINARY_DIR}/track3.txt COPYONLY)
configure_file(tracks/track4.txt ${CMAKE_CURRENT_BINARY_DIR}/track4.txt COPYONLY)