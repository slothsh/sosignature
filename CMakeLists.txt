cmake_minimum_required(VERSION 3.23.0)
project(slothsig VERSION 1.2.1 LANGUAGES CXX)

# Global compiler configuration
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_CXX_STANDARD 23)
    set(COMPILE_WARNINGS "/W4")
    set(COMPILE_OPTIMIZE "/O2")
    set(LINK_RUNTIME_LIB "/MT")
    add_compile_options("/W4" "/O2" "/MT")
else()
    set(CMAKE_CXX_STANDARD 20)
    set(COMPILE_WARNINGS "-Wall -Wpedantic")
    set(COMPILE_OPTIMIZE "-O3")
    add_compile_options("-Wall" "-Wpedantic" "-O3")
endif()

message(STATUS "Project source path: ${CMAKE_SOURCE_DIR}")

# Comiler Warnings & Run time library
message(STATUS "Setting compiler warnings to ${COMPILE_WARNINGS}")
message(STATUS "Setting compiler optimizations to ${COMPILE_OPTIMIZE}")
if (MSVC)
    message(STATUS "Linking MSVC run time library to ${LINK_RUNTIME_LIB}")
endif()

# Build Third-Party Dependencies
find_package(fmt REQUIRED)
find_package(cxxopts REQUIRED)

# Build application
add_executable(sloth)
target_sources(sloth PUBLIC ./src/sloth.cxx)
target_link_libraries(sloth PRIVATE fmt::fmt cxxopts::cxxopts)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_compile_options(sloth PRIVATE "/utf-8")
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
