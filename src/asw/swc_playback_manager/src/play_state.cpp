
#include <iostream>
#include <memory>

#include "playback_state_machine.hpp"
#include "states/idle_state.hpp"
#include "states/pause_state.hpp"
#include "states/play_state.hpp"


namespace AutosarMusicPlayer {
namespace Asw {
Common::ErrorCode PlayState::handlePlay(PlaybackManager& /*context*/) {
    std::cout << "PlayState: Already in Play state." << std::endl;
    return Common::ErrorCode::INVALID_OPERATION;
}

Common::ErrorCode PlayState::handlePause(PlaybackManager& context) {
    std::cout << "Transitioning from Play to Pause state." << std::endl;
    context.transitionTo(std::make_unique<PauseState>());
    return Common::ErrorCode::SUCCESS;
}

Common::ErrorCode PlayState::handleStop(PlaybackManager& context) {
    std::cout << "Transitioning from Play to Idle state." << std::endl;
    context.transitionTo(std::make_unique<IdleState>());
    return Common::ErrorCode::SUCCESS;
}

std::string PlayState::getStateName() const {
    return "PlayState";
}
}  // namespace Asw
}  // namespace AutosarMusicPlayer