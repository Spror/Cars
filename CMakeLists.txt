cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GoogleTest
########
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
##########

project(Cars)

set(SRC_LIST
    ElectricCar.cpp
    ElectricEngine.cpp
    HybridCar.cpp
    PetrolCar.cpp
    PetrolEngine.cpp
    Engine.cpp
    Car.cpp
)

set(INC_LIST
    ElectricCar.hpp
    ElectricEngine.hpp
    HybridCar.hpp
    PetrolCar.hpp
    PetrolEngine.hpp
    Engine.hpp
    Car.hpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(${PROJECT_NAME}-lib STATIC ${SRC_LIST})

add_executable(${PROJECT_NAME} main.cpp ${INC})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)





enable_testing()

# Creating test
enable_testing()
add_executable(${PROJECT_NAME}-test test/test.cpp )
target_link_libraries( ${PROJECT_NAME}-test
                       GTest::gtest_main  ${PROJECT_NAME}-lib)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-test )