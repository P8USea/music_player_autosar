// Thu vien cho trang thai "Play" (Dang phat)
#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP
#include "playback_state.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
class PlayState : public PlaybackState
{
   public:
    Common::ErrorCode handlePlay(PlaybackManager& /*context*/) override;

    Common::ErrorCode handlePause(PlaybackManager& context) override;

    Common::ErrorCode handleStop(PlaybackManager& context) override;

    std::string getStateName() const override;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // PLAY_STATE_HPP
