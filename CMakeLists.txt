project(Sidescroller-RPG)
cmake_minimum_required(VERSION 2.8)

find_package(SFML 2 COMPONENTS graphics window audio system REQUIRED)

include_directories(${SFML_INCLUDE_DIRS})

set(EXEC_NAME "rpg")

add_executable(${EXEC_NAME}
src/main.cpp
)

target_link_libraries(${EXEC_NAME} ${SFML_LIBRARIES})
