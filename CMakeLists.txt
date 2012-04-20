cmake_minimum_required(VERSION 2.8)
project(iptc_writer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(GTest)
find_package(Exiv2)

#add_subdirectory(src)

if(GTEST_FOUND)
  add_subdirectory(unittest)
endif(GTEST_FOUND)
