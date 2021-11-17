cmake_minimum_required(VERSION 3.14)

# Project settings.
set(PROJECT_UNIT_TESTS_NAME test)

# Gather the header and source files.
file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/tests/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

# Include paths.
set(UNIT_TESTS_INCLUDES ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Assign the include directories.
include_directories(${UNIT_TESTS_INCLUDES})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_UNIT_TESTS_NAME} ${UNIT_TESTS_SRC_FILES})
target_link_libraries(${PROJECT_UNIT_TESTS_NAME} gtest_main)

add_test(app ${PROJECT_UNIT_TESTS_NAME})
