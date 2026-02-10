#include "media_source_strategy.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
Common::ErrorCode MediaSourceStrategy::loadMediaSource(const std::string& source)
{
	(void)source;
	return Common::ErrorCode::INVALID_OPERATION;
}


std::vector<std::unique_ptr<Song>> MediaSourceStrategy::getSongs() const
{
	return {};
}

}  // namespace Asw
}  // namespace AutosarMusicPlayer
