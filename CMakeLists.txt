cmake_minimum_required(VERSION 3.15.0)
project(osig VERSION 1.0.0 LANGUAGES CXX)

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


# Third-party dependencies
if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    file(TO_CMAKE_PATH $ENV{LIBFMT_PATH} fmt_path)
    file(TO_CMAKE_PATH $ENV{CXXOPTS_PATH} cxxopts_path)
    set(fmtlib "fmtd.lib")
    set(fmtlib_path "libfmt_x64/lib")
elseif (${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    file(TO_CMAKE_PATH $ENV{LIBFMT_PATH} fmt_path)
    file(TO_CMAKE_PATH $ENV{CXXOPTS_PATH} cxxopts_path)
    set(fmtlib "libfmt.a")
    set(fmtlib_path "libfmt_x64/lib")
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")

message(STATUS ${fmt_path}/${fmtlib_path})
message(STATUS ${cxxopts_path})

# Build Third-Party Dependencies
find_library(LIBFMT NAMES ${fmtlib} PATHS ${fmt_path}/${fmtlib_path})
set(libfmt ${LIBFMT})

# Include third-party headers
include_directories(
    ${fmt_path}/include
    ${cxxopts_path}/include
)

# Build application
add_executable(sloth)
target_sources(sloth PUBLIC ./src/sloth.cxx)
set_target_properties(sloth PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(sloth PRIVATE ${LIBFMT})

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_compile_options(sloth PRIVATE "/utf-8")
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
