// Thu vien dinh nghia trang thai phat nhac
// Trang thai: Dang phat, Tam dung, Dung
#ifndef PLAYBACK_STATE_HPP
#define PLAYBACK_STATE_HPP
#include <string>

#include "app_error_codes.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
class PlaybackManager;  // Forward declaration
// Lop truu tuong dinh nghia trang thai phat nhac
class PlaybackState
{
   public:
    virtual ~PlaybackState() = default;
    virtual Common::ErrorCode handlePlay(PlaybackManager& context) = 0;
    virtual Common::ErrorCode handlePause(PlaybackManager& context) = 0;
    virtual Common::ErrorCode handleStop(PlaybackManager& context) = 0;
    virtual std::string getStateName() const = 0;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif  // !PLAYBACK_STATE_HPP
