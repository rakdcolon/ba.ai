cmake_minimum_required(VERSION 3.20)
project(BalatroRL)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable extra compiler warnings (optional)
if(MSVC)
add_compile_options(/W4)
else()
add_compile_options(-Wall -Wextra -pedantic)
endif()

# Specify the include directory (where header files are)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files from the src directory.
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Define the executable target
add_executable(BalatroRL ${SOURCES})