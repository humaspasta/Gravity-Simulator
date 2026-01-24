cmake_minimum_required(VERSION 3.16)
project(gravity_sim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gravity_sim src/main.cpp)

find_package(SFML REQUIRED COMPONENTS Graphics Window System)

target_link_libraries(gravity_sim
    SFML::Graphics
)
