#ifndef MEDIA_SOURCE_STRATEGY_HPP
#define MEDIA_SOURCE_STRATEGY_HPP

#include <memory>
#include <string>
#include <vector>

#include "app_error_codes.hpp"
#include "song.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop truu tuong dinh nghia chien luoc truy cap nguon media
class MediaSourceStrategy
{
   public:
    virtual ~MediaSourceStrategy() = default;
    virtual Common::ErrorCode loadMediaSource(const std::string& source);
    virtual std::vector<std::unique_ptr<Song>> getSongs() const;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !MEDIA
