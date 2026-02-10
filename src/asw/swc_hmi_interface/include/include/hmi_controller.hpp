#ifndef HMI_CONTROLLER_HPP
#define HMI_CONTROLLER_HPP

#include <memory>
#include <vector>

#include "hmi_controller.hpp"
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
    explicit HmiController(IPlaybackControl& playback_ctrl);

    void addObserver(const std::shared_ptr<HmiObserver>& observer);

    void userPlay();
    void userPause();
    void userStop();
    void userNextTrack();
    void userPreviousTrack();

    void notifyPlayStateChanged(Common::PlayerState state);
    void notifyTrackChanged(int trackId, const std::string& trackTitle);
    void notifyVolumeChanged(uint8_t newVolume);
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !HMI_CONTROLLER_HPP
