// Thu vien dinh nghia trang thai cho trang thai "Idle" (Dung)
#ifndef IDLE_STATE_HPP
#define IDLE_STATE_HPP
#include <iostream>
#include <memory>

#include "playback_state.hpp"
#include "playback_state_machine.hpp"
#include "play_state.hpp"  // Include sau khi định nghĩa IdleState để tránh circular dependency
namespace AutosarMusicPlayer {
namespace Asw {
class PlayState;  // Forward declaration tránh circular dependency

class IdleState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& context) override {
        // Logic chuyển từ trạng thái Idle sang Playing
        std::cout << "IdleState chuyển sang trạng thái Playing " << std::endl;

        // Tạo trạng thái mới và chuyển trạng thái 
        std::unique_ptr<PlaybackState> playState = std::make_unique<PlayState>();
        context.transitionTo(std::move(playState));

        return Common::ErrorCode::SUCCESS;



    }
    Common::ErrorCode handlePause(PlaybackManager& context) override;
    Common::ErrorCode handleStop(PlaybackManager& context) override;
    std::string getStateName() const override;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !IDLE
