cmake_minimum_required(VERSION 3.1.0)

project(qdnslookup_test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Network CONFIG REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} "main.cpp")

target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Core Qt5::Network)
