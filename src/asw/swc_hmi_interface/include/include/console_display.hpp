#ifndef CONSOLE_DISPLAY_HPP
#define CONSOLE_DISPLAY_HPP

#include <cstdint>
#include <string>

#include "hmi_observer.hpp"

namespace AutosarMusicPlayer {
namespace Asw {

// Console-based HMI observer implementation.
class ConsoleDisplay : public HmiObserver
{
   public:
    void onPlayStateChanged(Common::PlayerState state) override;
    void onTrackChanged(int trackId, const std::string& trackTitle) override;
    void onVolumeChanged(uint8_t newVolume) override;
};

}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif  // CONSOLE_DISPLAY_HPP
