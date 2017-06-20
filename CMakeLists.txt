cmake_minimum_required(VERSION 2.8.11)
project(QDocumentTabWidget)

set (CMAKE_CXX_STANDARD 14)



SET(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_ROOT}/include)

find_package(Qt5Widgets)

include_directories(${PROJECT_INCLUDE_DIR})
add_subdirectory(src)
add_subdirectory(example)