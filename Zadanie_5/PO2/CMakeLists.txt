cmake_minimum_required(VERSION 3.0)
project(Przetwarzanie_obrazu_2)
include_directories(inc)
file(GLOB SOURCE "src/*.c" "inc/*.h")
add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} m)