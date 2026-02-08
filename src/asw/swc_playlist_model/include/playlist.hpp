#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <memory>
#include <vector>

#include "song.hpp"

namespace AutosarMusicPlayer {
namespace Asw {

class Playlist
{
   public:
    Playlist() = default;

    // Cấm copy Playlist để tránh nhân bản bộ nhớ lãng phí
    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

    void addSong(std::unique_ptr<Song> song);

    Song* getSong(size_t index) const;

    size_t getSize() const
    {
        return songs_.size();
    }

   private:
    std::vector<std::unique_ptr<Song>> songs_;
};

}  // namespace Asw
}  // namespace AutosarMusicPlayer

#endif
