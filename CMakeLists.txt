cmake_minimum_required(VERSION 2.8.10)


set(PROJECT_NAME dynamixel_unitTest)
project(${PROJECT_NAME})



set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_SHARED_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall")
if ( UNIX )
    set( CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}" )
endif ( UNIX )



add_subdirectory(robotis)


add_executable(${PROJECT_NAME} unitTests/UnitTest_robotisV1.cpp)
target_link_libraries(${PROJECT_NAME} robotis boost_unit_test_framework)
