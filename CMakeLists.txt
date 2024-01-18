cmake_minimum_required(VERSION 3.10)
project(yolov8)

add_definitions(-std=c++11)
add_definitions(-w)
# option(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
find_package(CUDA REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

#cuda 
include_directories(/usr/local/cuda-11.8/targets/x86_64-linux/include)
link_directories(/usr/local/cuda-11.8/targets/x86_64-linux/lib)

# tensorrt 
include_directories(/opt/TensorRT-8.5.1.7//include/)
link_directories(/opt/TensorRT-8.5.1.7/lib/)


# include_directories(/mnt/Gu/softWare/TensorRT-8.4.1.5/include/)
# link_directories(/mnt/Gu/softWare/TensorRT-8.4.1.5/lib/)

#opencv 
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

#onnx2trt
add_subdirectory(${PROJECT_SOURCE_DIR}/onnx2trt)
#labels2Txt
add_subdirectory(${PROJECT_SOURCE_DIR}/labelsyaml2txt)

cuda_add_executable(yolov8 yolov8.cpp utils.cpp process.cu)

target_link_libraries(yolov8 nvinfer)
target_link_libraries(yolov8 cudart)
target_link_libraries(yolov8 nvonnxparser)
target_link_libraries(yolov8 ${OpenCV_LIBS})

add_definitions(-O2 -pthread)