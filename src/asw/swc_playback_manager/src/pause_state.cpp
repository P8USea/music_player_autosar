#include <iostream>
#include <memory>

#include "playback_state_machine.hpp"
#include "states/idle_state.hpp"
#include "states/pause_state.hpp"
#include "states/play_state.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
Common::ErrorCode PauseState::handlePlay(PlaybackManager& context) {
    std::cout << "Transitioning from Pause to Play state." << std::endl;
    context.transitionTo(std::make_unique<PlayState>());
    return Common::ErrorCode::SUCCESS;
}

Common::ErrorCode PauseState::handlePause(PlaybackManager& /*context*/) {
    std::cout << "PauseState: Already in Pause state." << std::endl;
    return Common::ErrorCode::INVALID_OPERATION;
}

Common::ErrorCode PauseState::handleStop(PlaybackManager& context) {
    std::cout << "Transitioning from Pause to Idle state.\n";
    context.transitionTo(std::make_unique<IdleState>());
    return Common::ErrorCode::SUCCESS;
}

std::string PauseState::getStateName() const {
    return "PauseState";
}
}  // namespace Asw
}  // namespace AutosarMusicPlayer