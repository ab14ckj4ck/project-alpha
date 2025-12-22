cmake_minimum_required(VERSION 3.16)
project(project_alpha LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(RAYLIB REQUIRED raylib)

add_executable(project_alpha
        src/main.cpp
        src/world/world-objects.h
        src/world/world-objects.cpp
        src/entities/entity-types.h
        src/entities/troops.cpp
        src/entities/troops.h
)

target_include_directories(project_alpha PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(project_alpha ${RAYLIB_LIBRARIES})
