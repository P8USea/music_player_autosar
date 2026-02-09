#include <iostream>
#include <memory>

#include "playback_state_machine.hpp"
#include "states/idle_state.hpp"
#include "states/play_state.hpp"


namespace AutosarMusicPlayer {
namespace Asw {
Common::ErrorCode IdleState::handlePlay(PlaybackManager& context) {
    std::cout << "Transitioning from Idle to Play state.\n";
    context.transitionTo(std::make_unique<PlayState>());
    return Common::ErrorCode::SUCCESS;
}

Common::ErrorCode IdleState::handlePause(PlaybackManager& /*context*/) {
    std::cout << "IdleState: Pause command ignored.\n";
    return Common::ErrorCode::INVALID_OPERATION;
}

Common::ErrorCode IdleState::handleStop(PlaybackManager& /*context*/) {
    std::cout << "IdleState: Stop command ignored.\n";
    return Common::ErrorCode::INVALID_OPERATION;
}

std::string IdleState::getStateName() const {
    return "IdleState";
}
}  // namespace Asw
}  // namespace AutosarMusicPlayer