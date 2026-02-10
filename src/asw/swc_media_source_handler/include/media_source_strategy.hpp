#ifndef MEDIA_SOURCE_STRATEGY_HPP
#define MEDIA_SOURCE_STRATEGY_HPP

#include <cstdint>
#include <memory>
#include <vector>

#include "app_error_codes.hpp"
#include "app_types.hpp"
#include "song.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop truu tuong dinh nghia chien luoc truy cap nguon media
class MediaSourceStrategy
{
   public:
    static constexpr uint16_t kDefaudelayMs =
        800;  // Thời gian giả lập delay kết nối (mặc định 800ms)
    virtual ~MediaSourceStrategy() = default;
    virtual Common::ErrorCode loadMediaSource(const Common::MediaSourceType& source) = 0;
    virtual std::vector<std::unique_ptr<Song>> getSongs() const;
    uint16_t delayMs = kDefaudelayMs;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !MEDIA
