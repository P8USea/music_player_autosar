#include "media_source_handler.hpp"

#include <iostream>

namespace AutosarMusicPlayer {
namespace Asw {

void MediaSourceHandler::setStrategy(std::unique_ptr<MediaSourceStrategy> strategy)
{
    strategy_ = std::move(strategy);
}

Common::ErrorCode MediaSourceHandler::loadMediaItems(std::vector<std::unique_ptr<Song>>& playlist)
{
    if (!strategy_) {
        return Common::ErrorCode::UNKNOWN_ERROR;
    }
    // Giả định nguồn media là một chuỗi mặc định
    auto err = strategy_->loadMediaSource(Common::MediaSourceType::BLUETOOTH);

    if (err != Common::ErrorCode::SUCCESS) {
        return err;
    }
    auto newSongs = strategy_->getSongs();
    if (newSongs.empty()) {
        return Common::ErrorCode::NOT_FOUND;
    }

    for (auto& song : newSongs) {
        playlist.push_back(std::move(song));
    }
    return Common::ErrorCode::SUCCESS;
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer
