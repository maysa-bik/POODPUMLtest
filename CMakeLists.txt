cmake_minimum_required(VERSION 3.10)
project(towerDefense VERSION 0.1.0 LANGUAGES C CXX)

set(SFML_DIR "C:/Program Files/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1/lib/cmake/SFML")


find_package(SFML 2.6.1 COMPONENTS graphics audio REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

add_executable(towerDefense 
        src/main.cpp
)

target_link_libraries(towerDefense sfml-graphics sfml-audio)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)