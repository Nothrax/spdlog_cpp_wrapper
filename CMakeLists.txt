cmake_minimum_required(VERSION 3.10)

project(Logger)

set(CMAKE_CXX_STANDARD 17)

if (NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif ()

file(GLOB_RECURSE source_files "${CMAKE_CURRENT_LIST_DIR}/src/*")
add_library(logger_lib STATIC ${source_files})
target_include_directories(logger_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include/")
target_link_libraries(logger_lib PUBLIC spdlog::spdlog_header_only)

