#include "gtest/gtest.h"
#include <memory>

#include "playback_state_machine.hpp"
#include "app_error_codes.hpp"

using namespace AutosarMusicPlayer::Asw;
using namespace AutosarMusicPlayer::Common;

class PlaybackManagerTest : public ::testing::Test {
public:
    std::unique_ptr<PlaybackManager> playbackManager;

    // SetUp chạy trước mỗi TEST_F
    void SetUp() override {
        // PlaybackManager khởi tạo mặc định sẽ vào trạng thái Idle
        playbackManager = std::make_unique<PlaybackManager>();
    }

    // TearDown chạy sau mỗi TEST_F
    void TearDown() override {
        playbackManager.reset();
    }
};

// TEST 1: TRẠNG THÁI KHỞI TẠO (IDLE)

TEST_F(PlaybackManagerTest, InitialIDLEState) {
    // Logic: Tại Idle, lệnh Pause và Stop là không hợp lệ (theo code idle_state.cpp)
    EXPECT_EQ(playbackManager->pause(), ErrorCode::INVALID_OPERATION);
    EXPECT_EQ(playbackManager->stop(), ErrorCode::INVALID_OPERATION);

    // Logic: Tại Idle, lệnh Play phải thành công
    EXPECT_EQ(playbackManager->play(), ErrorCode::SUCCESS);
}

// TEST 2: CHUYỂN ĐỔI TRẠNG THÁI (TRANSITIONS)

// Test: Idle -> Play
TEST_F(PlaybackManagerTest, TransitionIdleToPlay) {
    // Hành động: Gọi Play
    ErrorCode result = playbackManager->play();

    // Kiểm tra:
    EXPECT_EQ(result, ErrorCode::SUCCESS);

    // Kiểm tra trạng thái mới (PlayState):
    // - Gọi Play lần nữa -> INVALID_OPERATION (đã play rồi)
    // - Gọi Pause -> SUCCESS (cho phép pause)
    EXPECT_EQ(playbackManager->play(), ErrorCode::INVALID_OPERATION);
    EXPECT_EQ(playbackManager->pause(), ErrorCode::SUCCESS);
}

// Test: Play -> Pause
TEST_F(PlaybackManagerTest, TransitionPlayToPause) {
    // Setup: Đưa về trạng thái Play
    playbackManager->play();

    // Hành động: Gọi Pause
    ErrorCode result = playbackManager->pause();

    // Kiểm tra:
    EXPECT_EQ(result, ErrorCode::SUCCESS);

    // Kiểm tra trạng thái mới (PauseState):
    // - Gọi Pause lần nữa -> INVALID_OPERATION
    // - Gọi Play -> SUCCESS (Resume)
    EXPECT_EQ(playbackManager->pause(), ErrorCode::INVALID_OPERATION);
    EXPECT_EQ(playbackManager->play(), ErrorCode::SUCCESS);
}

// Test: Play -> Stop
TEST_F(PlaybackManagerTest, TransitionPlayToStop) {
    // Setup: Đưa về trạng thái Play
    playbackManager->play();

    // Hành động: Gọi Stop
    ErrorCode result = playbackManager->stop();

    // Kiểm tra:
    EXPECT_EQ(result, ErrorCode::SUCCESS);

    // Kiểm tra trạng thái mới (IdleState):
    // - Gọi Stop lần nữa -> INVALID_OPERATION
    // - Gọi Play -> SUCCESS
    EXPECT_EQ(playbackManager->stop(), ErrorCode::INVALID_OPERATION);
    EXPECT_EQ(playbackManager->play(), ErrorCode::SUCCESS);
}

// Test: Pause -> Stop
TEST_F(PlaybackManagerTest, TransitionPauseToStop) {
    // Setup: Idle -> Play -> Pause
    playbackManager->play();
    playbackManager->pause();

    // Hành động: Gọi Stop
    ErrorCode result = playbackManager->stop();

    // Kiểm tra:
    EXPECT_EQ(result, ErrorCode::SUCCESS);
    
    // Kiểm tra đã về Idle chưa
    EXPECT_EQ(playbackManager->play(), ErrorCode::SUCCESS);
}

// Test: Pause -> Play (Resume)
TEST_F(PlaybackManagerTest, TransitionPauseToPlayResume) {
    // Setup: Idle -> Play -> Pause
    playbackManager->play();
    playbackManager->pause();

    // Hành động: Gọi Play (Resume)
    ErrorCode result = playbackManager->play();

    EXPECT_EQ(result, ErrorCode::SUCCESS);

    // Đang ở PlayState thì không Play được nữa
    EXPECT_EQ(playbackManager->play(), ErrorCode::INVALID_OPERATION);
}


// TEST 3: CHỨC NĂNG CHƯA CÀI ĐẶT
    
TEST_F(PlaybackManagerTest, UnimplementedFunctions) {
    // Theo code playback_manager.cpp, 2 hàm này chưa implement
    EXPECT_EQ(playbackManager->nextTrack(), ErrorCode::NOT_FOUND);
    EXPECT_EQ(playbackManager->previousTrack(), ErrorCode::NOT_FOUND);
}