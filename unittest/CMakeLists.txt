# Breif - A minimal working CMakeLists.txt for goggle unittesting
# Author - Fredrik Persson - fpersson.se@gmail.com
# Licens - BSD
cmake_minimum_required (VERSION 2.6)
project(demo)

find_package(GTest REQUIRED)
find_package(Boost 1.4.2 COMPONENTS program_options filesystem system REQUIRED)

include_directories(${GTest_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS} ${Exiv2_INCLUDE_DIRS})

set(CORELIBS ${GTEST_BOTH_LIBRARIES} ${Boost_LIBRARIES} ${Exiv2_LIBRARIES})
set(CMAKE_CXX_FLAGS "-pthread")

add_executable(unittest ${CORELIBS} unittest.cpp ../src/CListFiles.cpp ../src/CExifWriter.cpp ../src/CXmlReader.cpp)
target_link_libraries(unittest ${CORELIBS}) 
