#include "media_source_strategy.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop chien luoc truy cap nguon media qua Bluetooth
class BtSourceStrategy : public MediaSourceStrategy
{
   public:
    Common::ErrorCode loadMedia(const std::string& source) override;
    std::vector<std::unique_ptr<Song>> getSongs() const override;
    
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
