
#include "include/hmi_controller.hpp"

namespace AutosarMusicPlayer {
namespace Asw {

HmiController::HmiController(IPlaybackControl& playback_ctrl)
    : playback_service_(playback_ctrl)
{
}

void HmiController::addObserver(const std::shared_ptr<HmiObserver>& observer)
{
    if (!observer) {
        return;
    }

    observers_.push_back(observer);
}

void HmiController::userPlay()
{
    playback_service_.play();
}

void HmiController::userPause()
{
    playback_service_.pause();
}

void HmiController::userStop()
{
    playback_service_.stop();
}

void HmiController::userNextTrack()
{
    playback_service_.nextTrack();
}

void HmiController::userPreviousTrack()
{
    playback_service_.previousTrack();
}

void HmiController::notifyPlayStateChanged(Common::PlayerState state)
{
    for (const auto& observer : observers_) {
        if (observer) {
            observer->onPlayStateChanged(state);
        }
    }
}

void HmiController::notifyTrackChanged(int trackId, const std::string& trackTitle)
{
    for (const auto& observer : observers_) {
        if (observer) {
            observer->onTrackChanged(trackId, trackTitle);
        }
    }
}

void HmiController::notifyVolumeChanged(uint8_t newVolume)
{
    for (const auto& observer : observers_) {
        if (observer) {
            observer->onVolumeChanged(newVolume);
        }
    }
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer