cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_CXX_STANDARD 11)

project(RabbitMQProject)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB files
     "*.h"
     "*.cpp"
)

add_executable(${PROJECT_NAME} ${files})

target_link_libraries(${PROJECT_NAME}
     PUBLIC app_utils)

target_link_libraries(${PROJECT_NAME}
     PUBLIC app_utils
     PUBLIC app_rabbitMQ_library
)

target_include_directories(${PROJECT_NAME}
     PUBLIC app_utils/src
     PUBLIC app_rabbitMQ_library/src)

message(STATUS "Adding subdirectories to package")
add_subdirectory(app_utils/src)
add_subdirectory(app_rabbitMQ_library/src)