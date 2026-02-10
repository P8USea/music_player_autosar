#ifndef HMI_CONTROLLER_HPP
#define HMI_CONTROLLER_HPP

#include <memory>
#include <vector>

#include "hmi_observer.hpp"
#include "i_playback_control.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop dieu khien giao dien nguoi dung HMI
class HmiController
{
   private:
    IPlaybackControl& playback_service_;
    std::vector<std::shared_ptr<HmiObserver>> observers_;

   public:
    explicit HmiController(IPlaybackControl& playback_ctrl) : playback_service_(playback_ctrl)
    {
    }
    void addObserver(std::shared_ptr<HmiObserver>& observer)
    {
        if (observer) {
            observers_.push_back(observer);
        }
    }
    void notifyPlayStateChanged(Common::PlayerState state)
    {
        for (const auto& observer : observers_) {
            observer->onPlayStateChanged(state);
        }
    }
    void notifyTrackChanged(int trackId, const std::string& trackTitle)
    {
        for (const auto& observer : observers_) {
            observer->onTrackChanged(trackId, trackTitle);
        }
    }
    void notifyVolumeChanged(uint8_t newVolume)
    {
        for (const auto& observer : observers_) {
            observer->onVolumeChanged(newVolume);
        }
    }
    void userPlay()
    {
        playback_service_.play();
    }
    void userPause()
    {
        playback_service_.pause();
    }
    void userStop()
    {
        playback_service_.stop();
    }
    void userNextTrack()
    {
        playback_service_.nextTrack();
    }
    void userPreviousTrack()
    {
        playback_service_.previousTrack();
    }
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !HMI_CONTROLLER_HPP
