cmake_minimum_required(VERSION 3.23)
project(Exam2 C)

set(CMAKE_C_STANDARD 99)

add_executable(queue src/queue.c src/queue.h)
add_executable(shell src/shell.c src/shell.h)
