#ifndef USB_SOURCE_HPP
#define USB_SOURCE_HPP
#include "media_source_strategy.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop chien luoc truy cap nguon media qua USB
class UsbSourceStrategy : public MediaSourceStrategy
{
   public:
    Common::ErrorCode loadMediaSource(const std::string& source) override;
    std::vector<std::unique_ptr<Song>> getSongs() const override;

     
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !USB_SOURCE_HPP
