#ifndef SONG_HPP
#define SONG_HPP

#include <string>

#include "app_types.hpp"

namespace AutosarMusicPlayer {
namespace Asw {

class Song
{
   public:
    Song(Common::id_t index, std::string title, std::string artist, Common::duration_t duration)
        : id_(index), title_(std::move(title)), artist_(std::move(artist)), duration_(duration)
    {
    }

    // Xai const
    Common::id_t getId() const
    {
        return id_;
    }
    const std::string& getTitle() const
    {
        return title_;
    }
    const std::string& getArtist() const
    {
        return artist_;
    }
    Common::duration_t getDuration() const
    {
        return duration_;
    }

   private:
    Common::id_t id_;
    std::string title_;
    std::string artist_;
    Common::duration_t duration_;
};

}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif
