#include <gtest/gtest.h>

#include <memory>

#include "playlist.hpp"
#include "song.hpp"
using namespace AutosarMusicPlayer::Asw;

// Case 1
TEST(PlaylistTest, AddSongSuccessfully)
{
    Playlist playlist;
    const int SONG_DURATION = 354;
    auto song = std::make_unique<Song>(1, "Bohemian Rhapsody", "Queen", SONG_DURATION);
    ASSERT_NE(song, nullptr);
    playlist.addSong(std::move(song));
    EXPECT_EQ(song, nullptr);  // song should be nullptr after move
    Song* retrievedSong = playlist.getSong(0);
    ASSERT_NE(retrievedSong, nullptr);
    EXPECT_EQ(retrievedSong->getTitle(), "Bohemian Rhapsody");
}
// Case 2
TEST(PlaylistTest, GetSongOutOfBounds)
{
    Playlist playlist;
    const int INVALID_INDEX = 999;
    Song* song = playlist.getSong(INVALID_INDEX);  // Index out of bounds
    EXPECT_EQ(song, nullptr);
}
