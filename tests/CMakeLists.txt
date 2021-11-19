cmake_minimum_required(VERSION 3.14)

# Setup packages.
find_package(GTest REQUIRED)

# Assign the include directories.
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Gather the header and source files.
file(GLOB UNIT_TESTS_INC_FILES ${PROJECT_SOURCE_DIR}/tests/*.hpp)
file(GLOB UNIT_TESTS_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

# Build.
add_executable(test_app ${UNIT_TESTS_SRC_FILES})
target_link_libraries(test_app PRIVATE GTest::gtest_main)

# Add test.
add_test(app test_app)
