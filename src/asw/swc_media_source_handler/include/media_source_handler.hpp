#ifndef MEDIA_SOURCE_HANDLER_HPP
#define MEDIA_SOURCE_HANDLER_HPP
#include <memory>
#include <vector>

#include "app_error_codes.hpp"
#include "media_source_strategy.hpp"
#include "song.hpp"
namespace AutosarMusicPlayer {
namespace Asw {
// Lop xu ly nguon media su dung cac chien luoc khac nhau
class MediaSourceHandler
{
   public:
    MediaSourceHandler() = default;
    Common::ErrorCode loadMediaItems(std::vector<std::unique_ptr<Song>>& playlist);
    std::vector<std::unique_ptr<Song>> getSongs() const;
    void setStrategy(std::unique_ptr<MediaSourceStrategy> strategy);

   private:
    std::unique_ptr<MediaSourceStrategy> strategy_;
};
}  // namespace Asw
}  // namespace AutosarMusicPlayer
#endif  // !MEDIA_SOURCE_HANDLER_HPP
