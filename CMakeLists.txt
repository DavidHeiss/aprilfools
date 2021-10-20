cmake_minimum_required(VERSION 3.0.0)
project(aprilfools VERSION 0.1.0)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(aprilfools main.c)
target_link_libraries(aprilfools apriltag)