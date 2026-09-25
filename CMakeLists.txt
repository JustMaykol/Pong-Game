cmake_minimum_required(VERSION 3.17)

project(Pong CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# En Windows se asume SFML instalado en C:/SFML (se puede cambiar con -DSFML_DIR=...)
if (WIN32 AND NOT DEFINED SFML_DIR)
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")
endif ()

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/main/*.cpp)

add_executable(pong ${SOURCES})

target_link_libraries(pong sfml-graphics sfml-window sfml-system sfml-audio)

# En Windows se copian las DLL de SFML junto al ejecutable
if (WIN32)
    file(GLOB SFML_DLLS "${SFML_DIR}/../../../bin/*.dll")
    file(COPY ${SFML_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
