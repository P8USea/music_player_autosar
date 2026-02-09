// Thu vien dinh nghia trang thai cho trang thai "Idle" (Dung)
#ifndef IDLE_STATE_HPP
#define IDLE_STATE_HPP
#include "playback_state.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
class IdleState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& context) override;
    Common::ErrorCode handlePause(PlaybackManager& context) override;
    Common::ErrorCode handleStop(PlaybackManager& context) override;
    std::string getStateName() const override;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // IDLE_STATE_HPP
