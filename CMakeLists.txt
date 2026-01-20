cmake_minimum_required(VERSION 3.20)
project(rayengine C)

set(CMAKE_C_STANDARD 11)
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")
add_executable(rayengine ${SOURCES})
target_include_directories(rayengine PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/lua_header
    ${CMAKE_SOURCE_DIR}/3rdlib/raylib-5.5/include
)

if (WIN32)
    target_link_libraries(rayengine PRIVATE
        ${CMAKE_SOURCE_DIR}/3rdlib/raylib-5.5/lib/raylibdll.lib
    )
    
    include_directories(${RAYLIB_DIR}/include)
    link_directories(${RAYLIB_DIR}/lib)
    link_directories(${CMAKE_SOURCE_DIR}/3rdlib/raylib-5.5/lib)
elseif (UNIX)
    set(CMAKE_PREFIX_PATH /usr/local/lib)
    find_package(raylib REQUIRED)
    include_directories(${RAYLIB_INCLUDE_DIRS})
    target_link_libraries(rayPro ${RAYLIB_LIBRARIES} m pthread dl)
endif()