cmake_minimum_required(VERSION 3.2)
project(ya-algorithm-training-1)

set(MODULES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/modules)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
foreach(SRC_FILE ${SRC_FILES})
    message(${SRC_FILE})
    get_filename_component(SRC_FILE_NAME ${SRC_FILE} NAME_WE)
    get_filename_component(SRC_FILE_DIR ${SRC_FILE} DIRECTORY)
    get_filename_component(SRC_FILE_DIR_NAME ${SRC_FILE_DIR} NAME)
    set(TARGET_NAME ${SRC_FILE_DIR_NAME}_${SRC_FILE_NAME})
    add_executable(${TARGET_NAME} ${SRC_FILE})
    set_target_properties(${TARGET_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")
    target_include_directories(${TARGET_NAME} PUBLIC ${MODULES_DIR}/kisstest/include)
endforeach()



