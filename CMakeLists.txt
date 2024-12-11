cmake_minimum_required(VERSION 3.20)
project(2024-11-19 LANGUAGES CXX)

# compiler options. (we only check for gcc)
if ("${CMAKE_C_COMPILER_ID}" STREQUAL GNU)
   string(APPEND CMAKE_C_FLAGS   " -Wall -Werror")
   string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror")
   if ("${CMAKE_BUILD_TYPE}" STREQUAL Debug)
     string(APPEND CMAKE_C_FLAGS   " -O0 -g3")
     string(APPEND CMAKE_CXX_FLAGS " -O0 -g3")
   endif()
endif()

add_subdirectory(2024-11-19)

# moved to attic
#   add_subdirectory(2024-11-20)
#   add_subdirectory(2024-11-21)
