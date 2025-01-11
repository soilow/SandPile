cmake_minimum_required(VERSION 3.12)
project(labwork3)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(image)
add_subdirectory(model)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE model)
target_link_libraries(main PRIVATE image)