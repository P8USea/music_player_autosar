#ifndef BT_SOURCE_HPP
#define BT_SOURCE_HPP

#include "app_types.hpp"
#include "media_source_strategy.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop chien luoc truy cap nguon media qua Bluetooth
class BtSourceStrategy : public MediaSourceStrategy
{
   public:
    Common::ErrorCode loadMediaSource(const Common::MediaSourceType& source) override;

    /// Trả về danh sách bài hát tìm thấy

    std::vector<std::unique_ptr<Song>> getSongs() const override;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif  // BT_SOURCE_HPP
