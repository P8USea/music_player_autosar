cmake_minimum_required(VERSION 3.28) 
project(AutosarMusicPlayer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror -Wshadow -Wnon-virtual-dtor)
endif()

include_directories(
    src/common/include
    src/asw/swc_playback_manager/include
    src/asw/swc_media_source_handler/include
    src/asw/swc_playlist_model/include
    src/asw/swc_hmi_interface/include
    src/bsw/hal/include
    src/bsw/cdd/include
    generated/rte
)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "generated/rte/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

#adding test subdirectory
enable_testing()
add_subdirectory(test)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} "-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")
    message(STATUS "Clang-tidy integration: ON")
endif()
