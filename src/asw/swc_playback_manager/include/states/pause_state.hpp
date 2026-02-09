// Thu vien cho trang thai "Pause" (Tam dung)
#ifndef PAUSE_STATE_HPP
#define PAUSE_STATE_HPP
#include "playback_state.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
class PauseState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& context) override;

    Common::ErrorCode handlePause(PlaybackManager& /*context*/) override;

    Common::ErrorCode handleStop(PlaybackManager& context) override;

    std::string getStateName() const override;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // PAUSE_STATE_HPP
