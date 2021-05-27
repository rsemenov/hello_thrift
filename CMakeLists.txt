cmake_minimum_required(VERSION 3.5)

project(HelloThrift)

add_compile_options(-Wall -Wextra -Wpedantic)

set(SOURCES_CLIENT hello_client.cpp gen-cpp/HelloSvc.cpp)
set(SOURCES_SERVER hello_server.cpp gen-cpp/HelloSvc.cpp)

find_library(THRIFT_LIB thrift HINTS /usr/local/lib)

add_executable(client ${SOURCES_CLIENT})
add_executable(server ${SOURCES_SERVER})

include_directories("/usr/local/include")

target_link_libraries(client ${THRIFT_LIB})
target_link_libraries(server ${THRIFT_LIB})

target_compile_features(client PRIVATE cxx_lambda_init_captures)
target_compile_features(server PRIVATE cxx_lambda_init_captures)
