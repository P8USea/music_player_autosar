# test/CMakeLists.txt
include(FetchContent)

#fetch GoogleTest, find_package doesn't work with FetchContent
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests 
    unit_tests/asw/test_playlist_model.cpp
    ../src/asw/swc_playlist_model/src/playlist.cpp
)

target_include_directories(unit_tests PRIVATE 
    ../src/common/include
    ../src/asw/swc_playlist_model/include
)

target_link_libraries(unit_tests GTest::gtest_main)

