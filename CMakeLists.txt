cmake_minimum_required(VERSION 3.21)
message(STATUS "Using CMake version ${CMAKE_VERSION}")

project(concept_using_concept LANGUAGES CXX VERSION 0.1.0)
message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Project version: ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ===========================
# LOCATION OF EXECUTABLE
# ===========================

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ===========================
# BUILD CONFIGURATION OPTIONS
# ===========================

option(RESET_DEFAULTS "Reset all options to default settings" OFF)
option(ENABLE_DEBUG "Enable Debugging Symbols (-O0 -g)" OFF)
option(ENABLE_CONCEPT_ERROR_DETAIL "Enable Verbose Compiler Errors for Concepts" ON)
option(ENABLE_PROFILING "Enable Profiling (-pg, for gprof/perf)" OFF)


# ===========================
# HANDLE RESET_DEFAULTS OPTION
# ===========================

if (RESET_DEFAULTS)
    message(STATUS "Resetting all options to default settings (turning them OFF)...")
    set(ENABLE_DEBUG OFF CACHE BOOL "Disable Debugging Symbols (Reset to Default)" FORCE)
    set(ENABLE_PROFILING OFF CACHE BOOL "Disable Profiling (Reset to Default)" FORCE)
    set(ENABLE_CONCEPT_ERROR_DETAIL ON CACHE BOOL "Enable Verbose Compiler Errors for Concepts (Default)" FORCE)
endif()


# ===========================
# APPLY COMPILER OPTIONS BASED ON CONFIGURATION
# ===========================

if (ENABLE_DEBUG)
    set(CMAKE_CXX_FLAGS "-O0 -g")
endif()

# Allow profiling 
if (ENABLE_PROFILING)
    add_compile_options(-pg)
endif()


# Enable verbose error messages for C++ Concepts (if using GCC)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND ENABLE_CONCEPT_ERROR_DETAIL)
    add_compile_options(-fconcepts-diagnostics-depth=5)
endif()


# ===========================
# SOURCE FILES
# ===========================

set (SRC_FILES
    src/concept_using_concept.cpp
)

add_executable(concept_using_concept ${SRC_FILES})


# ===========================
# INCLUDE DIRECTORIES
# ===========================

target_include_directories(concept_using_concept PRIVATE include)