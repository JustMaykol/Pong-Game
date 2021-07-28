cmake_minimum_required(VERSION 3.17)

project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project src/main/main.cpp src/main/main.h src/main/menu/Menu.cpp src/main/menu/Menu.h src/main/game/Game.cpp src/main/game/Game.h src/main/object/ball/BallObject.cpp src/main/object/ball/BallObject.h src/main/util/Location.cpp src/main/util/Location.h src/main/game/duo/DuoGame.cpp src/main/game/duo/DuoGame.h src/main/object/paddle/PaddleObject.cpp src/main/object/paddle/PaddleObject.h src/main/game/solo/SoloGame.cpp src/main/game/solo/SoloGame.h src/main/game/abstract/AbstractGame.h src/main/object/abstract/AbstractObject.h)

include_directories(headers /usr/include c:/SFML/include)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Project ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()