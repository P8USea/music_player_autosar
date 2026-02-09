// Thu vien dinh nghia trang thai phat nhac
// Trang thai: Dang phat, Tam dung, Dung
#ifndef PLAYBACK_STATE_MACHINE_HPP
#define PLAYBACK_STATE_MACHINE_HPP

#include <memory>
#include "i_playback_control.hpp"
#include "playback_state.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop quan ly trang thai phat nhac
class PlaybackManager : public IPlaybackControl
{
   public:
    PlaybackManager();
    Common::ErrorCode play() override;
    Common::ErrorCode pause() override;
    Common::ErrorCode stop() override;
    Common::ErrorCode nextTrack() override;
    Common::ErrorCode previousTrack() override;
    void transitionTo(std::unique_ptr<PlaybackState> state);
    void getCurrentStateName() const;

   private:
    std::unique_ptr<PlaybackState> currentState_;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif  // !PLAYBACK_STATE_MACHINE_HPP
