cmake_minimum_required(VERSION 3.10)
project(mt)

set(CMAKE_CXX_STANDARD 17)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_executable(mt, main.c)
target_link_libraries(mt PRIVATE Threads::Threads)
