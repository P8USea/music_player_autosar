#include <iostream>
#include <utility>

#include "playback_state_machine.hpp"
#include "states/idle_state.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
PlaybackManager::PlaybackManager() : currentState_(std::make_unique<IdleState>())
{
}

Common::ErrorCode PlaybackManager::play()
{
    // Uy thac hanh vi cho trang thai hien tai
    if (!currentState_) {
        return Common::ErrorCode::INVALID_PARAMETER;
    }
    return currentState_->handlePlay(*this);
}

Common::ErrorCode PlaybackManager::pause()
{
    // Uy thac hanh vi cho trang thai hien tai
    if (!currentState_) {
        return Common::ErrorCode::INVALID_PARAMETER;
    }
    return currentState_->handlePause(*this);
}

Common::ErrorCode PlaybackManager::stop()
{
    // Uy thac hanh vi cho trang thai hien tai
    if (!currentState_) {
        return Common::ErrorCode::INVALID_PARAMETER;
    }
    return currentState_->handleStop(*this);
}

Common::ErrorCode PlaybackManager::nextTrack()
{
    // Chua trien khai, tra ve NOT_FOUND de bao hieu
    std::cout << "Next track: not implemented\n";
    return Common::ErrorCode::NOT_FOUND;
}

Common::ErrorCode PlaybackManager::previousTrack()
{
    // Chua trien khai, tra ve NOT_FOUND de bao hieu
    std::cout << "Previous track: not implemented\n";
    return Common::ErrorCode::NOT_FOUND;
}

void PlaybackManager::transitionTo(std::unique_ptr<PlaybackState> state)
{
    // Bao ve truong hop chuyen trang thai khong hop le
    if (!state) {
        std::cout << "Transition failed: null state\n";
        return;
    }
    currentState_ = std::move(state);
}

void PlaybackManager::getCurrentStateName() const
{
    // In ra ten trang thai hien tai (de debug)
    if (!currentState_) {
        std::cout << "Current state: <null>\n";
        return;
    }
    std::cout << "Current state: " << currentState_->getStateName() << "\n";
}
}  // namespace Asw
}  // namespace AutosarMusicPlayer
