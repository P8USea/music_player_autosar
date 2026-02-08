// Thu vien cho trang thai "Play" (Dang phat)
#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP
#include <iostream>
#include <memory>

#include "playback_state.hpp"
#include "playback_state_machine.hpp"
#include "states/idle_state.hpp"
#include "states/pause_state.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
class PlayState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& /*context*/) override {
        std::cout << "PlayState: already in Playing state" << std::endl;
        return Common::ErrorCode::SUCCESS;
    }

    Common::ErrorCode handlePause(PlaybackManager& context) override {
        std::cout << "PlayState -> PauseState" << std::endl;
        std::unique_ptr<PlaybackState> pauseState = std::make_unique<PauseState>();
        context.transitionTo(std::move(pauseState));
        return Common::ErrorCode::SUCCESS;
    }

    Common::ErrorCode handleStop(PlaybackManager& context) override {
        std::cout << "PlayState -> IdleState" << std::endl;
        std::unique_ptr<PlaybackState> idleState = std::make_unique<IdleState>();
        context.transitionTo(std::move(idleState));
        return Common::ErrorCode::SUCCESS;
    }

    std::string getStateName() const override {
        return "Play";
    }
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !PLAY_STATE_HPP
