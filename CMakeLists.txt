cmake_minimum_required(VERSION 2.6)
project("stl-algorithms")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/Wall" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

include_directories(SYSTEM /home/mx/catchorg)

file(GLOB SOURCES "*.cpp")

add_executable(stl-algorithms ${SOURCES})
