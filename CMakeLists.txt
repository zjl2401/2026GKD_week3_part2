cmake_minimum_required(VERSION 3.16)
project(TaskScheduler VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 单一可执行文件，源码在当前目录
add_executable(TaskScheduler
    main.cpp
)

target_include_directories(TaskScheduler PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

