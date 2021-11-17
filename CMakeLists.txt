cmake_minimum_required(VERSION 3.14)

# Project settings.
project(app)
set(CMAKE_CXX_STANDARD 17)

# Gather the header and source files.
file(GLOB INC_FILES ${PROJECT_SOURCE_DIR}/src/*.hpp)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Setup Conan.
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Unit tests.
add_subdirectory(tests)

# Assign the include directories.
include_directories("${PROJECT_SOURCE_DIR}/include")

# Build.
add_executable(app ${INC_FILES} ${SRC_FILES})
target_link_libraries(app ${CONAN_LIBS})
