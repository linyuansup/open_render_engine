cmake_minimum_required(VERSION 3.26)
project(open_render_engine)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

set(src
    api.h
    render_engine.h
    render_engine.cpp)

add_subdirectory(v5sdk)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_executable(open_render_engine main.cpp main.h ${src})
else()
    add_library(open_render_engine SHARED ${src})
endif()

set_target_properties(open_render_engine PROPERTIES CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(open_render_engine PRIVATE EXPORTED_FUNCTION_VISIBILITY=1)

target_link_libraries(open_render_engine libV5SDK)
