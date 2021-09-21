cmake_minimum_required(VERSION 3.15)
project(codeforces)

set(CMAKE_CXX_STANDARD 14)

add_executable(tmp templates/tmp.cpp)
add_executable(d contest/1538/d/d.cpp)
add_executable(solve luogu/mobius/P3911/solve.cpp)

add_executable(e contest/1566/e/e.cpp)

add_executable(a contest/1566/a/a.cpp)
add_executable(b contest/1566/b/b.cpp)
add_executable(c contest/1566/c/c.cpp)
add_executable(d1 contest/1566/d1/d1.cpp)

add_executable(main leetcode/main.cpp)
