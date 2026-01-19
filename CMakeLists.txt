# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(rayPro)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Automatically include all .c files in src and its subdirectories
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.c")

# Add the executable
add_executable(rayPro ${SOURCES})

# Include directories
target_include_directories(rayPro PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/lua_header
    ${CMAKE_SOURCE_DIR}/test
)

# Platform-specific settings
if (WIN32)
    # Windows-specific settings
    set(RAYLIB_DIR "C:/raylib") # 假设 raylib 安装在 C:/raylib 这里要修改为你实际的路径
    include_directories(${RAYLIB_DIR}/include)
    link_directories(${RAYLIB_DIR}/lib)
    target_link_libraries(rayPro raylib)
elseif (UNIX)
    # Unix-specific settings
    set(CMAKE_PREFIX_PATH /usr/local/lib)
    find_package(raylib REQUIRED)
    include_directories(${RAYLIB_INCLUDE_DIRS})
    link_directories(/usr/local/lib)
    target_link_libraries(rayPro raylib m pthread dl)
    target_link_libraries(rayPro ${RAYLIB_LIBRARIES} m pthread dl)
endif()
