cmake_minimum_required(VERSION 3.14)

# Setup Hunter.
include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.317.tar.gz"
        SHA1 "fbdd94b1966d351384e27b02c8d134915b1131d6"
)

# Project settings.
project(app)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add packages.
hunter_add_package(GTest)

# Assign the include directories.
include_directories("${PROJECT_SOURCE_DIR}/include")

# Gather the header and source files.
file(GLOB INC_FILES ${PROJECT_SOURCE_DIR}/src/*.hpp)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Build.
add_executable(app ${INC_FILES} ${SRC_FILES})
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Unit tests.
enable_testing()
add_subdirectory(tests)
