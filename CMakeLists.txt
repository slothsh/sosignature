cmake_minimum_required(VERSION 3.15.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(sosig VERSION 1.0.0 LANGUAGES CXX)

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
add_executable(sosig)
target_sources(sosig PUBLIC ./src/sosignature.cxx)
set_target_properties(sosig PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(sosig PRIVATE ${LIBFMT})

if (${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_compile_options(sosig PRIVATE "/utf-8")
endif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
