project(Lab08_forreal)
cmake_minimum_required(VERSION 3.10)

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++17)

add_library(applibrary SHARED PokemonFactory.cpp IRole.cpp Type.cpp)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary)

# Link runMain with the main.cpp and applibrary
add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)
