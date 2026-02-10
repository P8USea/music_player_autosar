#include "include/console_display.hpp"

#include <iostream>

namespace AutosarMusicPlayer {
namespace Asw {
namespace {

const char* toString(Common::PlayerState state)
{
    switch (state) {
        case Common::PlayerState::IDLE:
            return "IDLE";
        case Common::PlayerState::PLAYING:
            return "PLAYING";
        case Common::PlayerState::PAUSED:
            return "PAUSED";
        case Common::PlayerState::STOPPED:
            return "STOPPED";
        case Common::PlayerState::ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

}  // namespace

void ConsoleDisplay::onPlayStateChanged(Common::PlayerState state)
{
    std::cout << "[HMI] State: " << toString(state) << '\n';
}

void ConsoleDisplay::onTrackChanged(int trackId, const std::string& trackTitle)
{
    std::cout << "[HMI] Track: " << trackId << " - " << trackTitle << '\n';
}

void ConsoleDisplay::onVolumeChanged(uint8_t newVolume)
{
    std::cout << "[HMI] Volume: " << static_cast<unsigned>(newVolume) << '\n';
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer
