project(Sidescroller-RPG)
cmake_minimum_required(VERSION 2.8)

find_package(SFML 2 COMPONENTS graphics window audio system REQUIRED)

add_compile_options(-std=c++11 -pedantic -Wall -Wextra -Wshadow)

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_definitions(-DSSRPG_DEBUG)
endif()

include_directories(${SFML_INCLUDE_DIRS})

set(EXEC_NAME "rpg")

add_executable(${EXEC_NAME}
src/main.cpp
src/Map.hpp
src/Map.cpp
)

target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES})
