cmake_minimum_required(VERSION 3.10)
project(labelsyaml2txt)
add_executable(labelsyaml2txt labelsyaml2txt.cpp)


find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})
target_link_libraries(labelsyaml2txt yaml-cpp)
