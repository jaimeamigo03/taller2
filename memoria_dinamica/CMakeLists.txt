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

add_executable(punteros_test punteros_test.cpp)

add_executable(lista_enlazada lista_enlazada/lista_enlazada_main.cpp lista_enlazada/lista_enlazada.cpp)
add_executable(lista_enlazada_test lista_enlazada/lista_enlazada_test.cpp lista_enlazada/lista_enlazada.cpp)

target_link_libraries(
  punteros_test
  gtest_main
)

target_link_libraries(
  lista_enlazada_test
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(punteros_test)
gtest_discover_tests(lista_enlazada_test)