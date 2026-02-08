// Thu vien cho trang thai "Pause" (Tam dung)
#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP
#include <iostream>
#include <memory>

#include "playback_state.hpp"
#include "playback_state_machine.hpp"
#include "play_state.hpp"
#include "idle_state.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
class PauseState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& context) override {
        std::cout << "PauseState chuyển sang trạng thái Playing " << std::endl;
        std::unique_ptr<PlaybackState> playState = std::make_unique<PlayState>();
        context.transitionTo(std::move(playState));
        return Common::ErrorCode::SUCCESS;
    }

    Common::ErrorCode handlePause(PlaybackManager& /*context*/) override {
        std::cout << "PauseState: đã ở trạng thái Pause " << std::endl;
        return Common::ErrorCode::SUCCESS;
    }

    Common::ErrorCode handleStop(PlaybackManager& context) override {
        std::cout << "PauseState chuyển sang trạng thái Idle " << std::endl;
        std::unique_ptr<PlaybackState> idleState = std::make_unique<IdleState>();
        context.transitionTo(std::move(idleState));
        return Common::ErrorCode::SUCCESS;
    }

    std::string getStateName() const override {
        return "Pause";
    }
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !PAUSE_STATE_HPP
