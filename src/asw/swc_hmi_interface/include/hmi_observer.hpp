#ifndef HMI_OBSERVER_HPP
#define HMI_OBSERVER_HPP

#include <cstdint>
#include <string>

#include "app_types.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop giao dien cho cac doi tuong quan sat HMI
class HmiObserver
{
   public:
    virtual ~HmiObserver() = default;
    virtual void onPlayStateChanged(Common::PlayerState state) = 0;
    virtual void onTrackChanged(int trackId, const std::string& trackTitle) = 0;
    virtual void onVolumeChanged(uint8_t newVolume) = 0;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !HMI_OBSERVER_HPP
