cmake_minimum_required(VERSION 3.0.0)
project(ProgrammingChallenges VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_OSX_ARCHITECTURES "arm64")

# Add all subdirectories within the 'leetcode' directory
file(GLOB leetcode_subdirs "leetcode/*")
foreach(subdir ${leetcode_subdirs})
    if(IS_DIRECTORY ${subdir})
        add_subdirectory(${subdir})
    endif()
endforeach()
