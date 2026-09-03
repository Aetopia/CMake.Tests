cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src/obj")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/src/obj")

include(FetchContent)
FetchContent_Declare(minhook GIT_REPOSITORY https://github.com/TsudaKageyu/minhook.git GIT_TAG v1.3.4)
FetchContent_MakeAvailable(minhook)


add_executable(app "${CMAKE_SOURCE_DIR}/src/app/main.c")
add_library(lib SHARED "${CMAKE_SOURCE_DIR}/src/lib/main.c")

set_target_properties(lib PROPERTIES PREFIX "" OUTPUT_NAME "th10" SUFFIX ".dll")
set_target_properties(app PROPERTIES PREFIX "" OUTPUT_NAME "th10" SUFFIX ".com")