#include "playlist.hpp"

#include <cstddef>
namespace AutosarMusicPlayer {
namespace Asw {
void Playlist::addSong(std::unique_ptr<Song> song)
{
    if (song != nullptr) {
        songs_.push_back(std::move(song));
    }
}
Song* Playlist::getSong(size_t index) const
{
    if (index < songs_.size()) {
        return songs_[index].get();
    }
    return nullptr;
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer
