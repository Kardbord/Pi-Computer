cmake_minimum_required (VERSION 2.4)
project (Assign5)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -lpthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

    add_executable(Assign5
                   # add source code files here
                  )
