#include <chrono>
#include <thread>

#include "app_error_codes.hpp"
#include "strategies/bt_source.hpp"

namespace AutosarMusicPlayer {
namespace Asw {
Common::ErrorCode BtSourceStrategy::loadMediaSource(const Common::MediaSourceType& source)
{
    // Giả lập delay kết nối
    std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));

    // Logic giả định nếu soure rỗng gây ra lỗi
    if (source != Common::MediaSourceType::BLUETOOTH) {
        return Common::ErrorCode::INVALID_PARAMETER;
    }

    // Giả lập kết nối thành công

    return Common::ErrorCode::SUCCESS;
}
std::vector<std::unique_ptr<Song>> BtSourceStrategy::getSongs() const
{
    std::vector<std::unique_ptr<Song>> playlist;
    // Sử dụng Move Semantics để chuyển quyền sở hữu vector ra ngoài
    return playlist;
}
}  // namespace Asw
}  // namespace AutosarMusicPlayer
