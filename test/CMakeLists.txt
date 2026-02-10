cmake_minimum_required(VERSION 3.14)
project(AutomotiveMusicPlayer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. SETUP GOOGLETEST
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Trỏ ra ngoài thư mục 'test', vào 'src'
set(PROJECT_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..") 
set(SWC_PLAYBACK_PATH "${PROJECT_ROOT_DIR}/src/asw/swc_playback_manager")
set(SWC_PLAYLIST_PATH "${PROJECT_ROOT_DIR}/src/asw/swc_playlist_model")

# 1. Tìm source file (.cpp)
file(GLOB_RECURSE SOURCE_FILES 
    "${SWC_PLAYBACK_PATH}/src/*.cpp"
    "${SWC_PLAYLIST_PATH}/src/*.cpp"
)

# 2. Tìm header dir
set(HEADER_DIRS 
    "${SWC_PLAYBACK_PATH}/include"
    "${SWC_PLAYLIST_PATH}/include"
)

# 3. Tạo Library
add_library(music_player_lib STATIC ${SOURCE_FILES})
target_include_directories(music_player_lib PUBLIC ${HEADER_DIRS})

# 4. Tìm file Test
# Vì file CMake đang ở trong folder 'test', nên chỉ cần tìm file cpp hiện tại
file(GLOB_RECURSE TEST_FILES "*.cpp")

# 5. Build Executable
enable_testing()
add_executable(unit_tests ${TEST_FILES})

target_link_libraries(unit_tests PRIVATE 
    music_player_lib 
    gtest_main
    pthread
)

include(GoogleTest)
gtest_discover_tests(unit_tests)