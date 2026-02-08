// Thu vien giao dien cho dieu khien phat nhac
// Cac chuc nang: phat, tam dung, dung, bai tiep theo, bai truoc do

#ifndef I_PLAYBACK_CONTROL_HPP
#define I_PLAYBACK_CONTROL_HPP

#include "app_error_codes.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
class IPlaybackControl
{
   public:
    virtual ~IPlaybackControl() = default;
    virtual Common::ErrorCode play() = 0;
    virtual Common::ErrorCode pause() = 0;
    virtual Common::ErrorCode stop() = 0;
    virtual Common::ErrorCode nextTrack() = 0;
    virtual Common::ErrorCode previousTrack() = 0;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !I_PLAYBACK_CONTROL_HPP
