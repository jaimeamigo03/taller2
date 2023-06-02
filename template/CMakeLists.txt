cmake_minimum_required(VERSION 3.0)

project(clase1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

include (CTest)


add_executable(lista_enlazada lista_enlazada/lista_enlazada_main.cpp)
add_executable(lista_enlazada_test lista_enlazada/lista_enlazada_test.cpp)

target_link_libraries(
  lista_enlazada_test
  gtest_main
)


include(GoogleTest)
gtest_discover_tests(lista_enlazada_test)
